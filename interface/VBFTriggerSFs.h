#include <TFile.h>
#include <TH3F.h>

/** \class VBFTriggerSFs
 *
 * Class to access jet legs efficiency of the VBFHTauTau trigger
 * \author Chiara Amendola, CEA
 *
 */


class VBFTriggerSFs {
 public:
  VBFTriggerSFs(std::string_view input_file);
  ~VBFTriggerSFs();
  
  float getJetsEfficiencyData (float VBFjets_mjj, float VBFjet1_pt, float VBFjet2_pt, int unc_scale = 0) const;
  float getJetsEfficiencyMC   (float VBFjets_mjj, float VBFjet1_pt, float VBFjet2_pt, int unc_scale = 0) const;
  float getJetsSF             (float VBFjets_mjj, float VBFjet1_pt, float VBFjet2_pt, int unc_scale = 0) const;
  
 private:
  static float getHistoContent    (const TH3F& hist, float x, float y,float z, int unc_scale); 
  static TH3F  *loadHisto         (TFile& file, std::string_view name);
  static bool  JetsValidityRegion (float VBFjets_mjj, float VBFjet1_pt, float VBFjet2_pt); 

 protected: 
  TH3F* eff_data; 
  TH3F* eff_mc;
  TH3F* sf;
};
