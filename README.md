# VBFHTauTau Trigger Scale Factors
Currently, only jet legs efficiencies and scale factors are available in this repo. 
See: [TauPOG meeting, 9/11/2020](https://indico.cern.ch/event/973626/contributions/4100308/attachments/2139477/3604467/TauPOG_2020_11_9.pdf).

Efficiencies and SFs are given as 3D histograms as a function of 
* invariant mass
* leading jet pT
* sub-leading jet pT

in the highest invariant mass jet pair of the event.

The scale factors should be applied to events firing the VBFHTauTau trigger and satisfying:
`mjj > 800 GeV && pT1 > 140 GeV && pT2 > 60 GeV`

## 2017 Data and MC
The VBF trigger is online only for 2017D-E-F, corresponding to 27.12/fb (i.e. 65.3% of the full 2017 luminosity).\
The scale factors and efficiencies are provided for the recommended trigger path:
`HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg`

They are computed w.r.t. events firing the di-tauh paths recommended for 2017 analyses: 
`HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg`
`HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg`
`HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg`


## 2018 Data and MC
The VBF trigger covers the full 2018 data-taking.\
The scale factors and efficiencies are provided for the recommended trigger paths:

| Path                                                     |        dataset               |
|----------------------------------------------------------|------------------------------|
|```HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1```    |  Data (Run < 317509)         |
|```HLT_VBF_DoubleLooseChargedIsoPFTauHPS20_Trk1_eta2p1``` | 	Data (Run >= 317509) and MC |


They are computed w.r.t. events firing the di-tauh paths recommended for 2018 analyses:

| Path                                                         |        dataset               |
|--------------------------------------------------------------|------------------------------|
|`HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg`    |  Data (Run < 317509)         |
|`HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg`   |  Data (Run < 317509)         |
|`HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg`            |  Data (Run < 317509)         |
|`HLT_DoubleMediumChargedIsoPFTauHPS35_Trk1_eta2p1_Reg`        | 	Data (Run >= 317509) and MC |

