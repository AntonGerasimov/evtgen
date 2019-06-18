#ifndef EVTOMEGAOMEGA_HH
#define EVTOMEGAOMEGA_HH

#include "EvtGenBase/EvtDecayAmp.hh"
#include <EvtGammaMatrix.hh>
#include "EvtGenBase/EvtComplex.hh"
#include "EvtGenBase/EvtVector4R.hh"
#include "EvtGenBase/EvtVector3R.hh"


class EvtParticle;

class EvtOmegaOmega:public  EvtDecayAmp  {

public:

  EvtOmegaOmega() {}
  virtual ~EvtOmegaOmega();

  std::string getName();
  EvtDecayBase* clone();

  void initProbMax();
  void init();
  void HadronicAmp( EvtParticle* parent, 
                                 EvtParticle* child, 
                                 EvtVector4C* T,
                                 const int i, 
                                 const int j );
  EvtVector4C EvtSigmaCurrent(const EvtDiracSpinor &d, const EvtDiracSpinor &dp) ;

  void decay(EvtParticle *p); 

};

#endif
