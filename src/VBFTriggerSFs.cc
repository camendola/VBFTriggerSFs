#include "VBFTriggersSFs/interface/VBFTriggerSFs.h"

#include <sstream>

VBFTriggerSFs::VBFTriggerSFs(std::string_view input_file)
{
  TFile file(input_file.data(), "READ");
  if(file.IsZombie()) {
    std::ostringstream ss;
    ss << "VBFTriggerSFs::VBFTriggerSFs: cannot open \"" << input_file.data() << "\".";
    throw std::runtime_error(ss.str());
  }
  eff_data = loadHisto(file, "DataEff_mjj_pT1_pT2"); 
  eff_mc   = loadHisto(file, "MCEff_mjj_pT1_pT2");
  sf       = loadHisto(file, "SF_mjj_pT1_pT2");
}

float VBFTriggerSFs::getJetsEfficiencyData(float VBFjets_mjj, float VBFjet1_pt, float VBFjet2_pt, int unc_scale) const
{
  return (JetsValidityRegion (VBFjets_mjj, VBFjet1_pt, VBFjet2_pt) ? getHistoContent(*eff_data, VBFjets_mjj, VBFjet1_pt, VBFjet2_pt, unc_scale) : 1.);
}

float VBFTriggerSFs::getJetsEfficiencyMC(float VBFjets_mjj, float VBFjet1_pt, float VBFjet2_pt, int unc_scale) const
{
  return (JetsValidityRegion (VBFjets_mjj, VBFjet1_pt,  VBFjet2_pt) ? getHistoContent(*eff_mc, VBFjets_mjj, VBFjet1_pt, VBFjet2_pt, unc_scale) : 1.);
}

float VBFTriggerSFs::getJetsSF(float VBFjets_mjj, float VBFjet1_pt, float VBFjet2_pt, int unc_scale) const
{
  return (JetsValidityRegion (VBFjets_mjj, VBFjet1_pt, VBFjet2_pt) ? getHistoContent(*sf,  VBFjets_mjj, VBFjet1_pt, VBFjet2_pt, unc_scale) : 1.);
}


float VBFTriggerSFs::getHistoContent(const TH3F& histo, float x, float y, float z, int unc_scale)
{
  int nbinsx = histo.GetNbinsX();
  int nbinsy = histo.GetNbinsY();
  int nbinsz = histo.GetNbinsZ();
  
  int ibinx = histo.GetXaxis()->FindBin(x);
  int ibiny = histo.GetYaxis()->FindBin(y);
  int ibinz = histo.GetZaxis()->FindBin(z);
  
  if (ibinx == 0)     ibinx = 1;
  if (ibinx > nbinsx) ibinx = nbinsx;
  
  if (ibiny == 0)     ibiny = 1;
  if (ibiny > nbinsy) ibiny = nbinsy;

  if (ibinz == 0)     ibinz = 1;
  if (ibinz > nbinsz) ibinz = nbinsz;

  return (unc_scale == 0? histo.GetBinContent(ibinx, ibiny, ibinz) :  histo.GetBinError(ibinx, ibiny, ibinz));
}


TH3F* VBFTriggerSFs::loadHisto(TFile& file, std::string_view name)
{
  TH3F* histo = (TH3F*) (file.Get(name.data()));
  if(!histo) {
    std::ostringstream ss;
    ss << "VBFTriggerSFs::VBFTriggerSFs: cannot to load histogram \"" << name << "\" from  \""
       << file.GetName() << "\".";
    throw std::runtime_error(ss.str());
  }
  return histo;
}

bool VBFTriggerSFs::JetsValidityRegion(float VBFjets_mjj, float VBFjet1_pt, float VBFjet2_pt)
{
  return (VBFjet1_pt > 140. && VBFjet2_pt > 60. && VBFjets_mjj > 800.); 
}

