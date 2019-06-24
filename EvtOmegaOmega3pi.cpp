#include "EvtGenBase/EvtPatches.hh"
#include <stdlib.h>
#include <iostream>
#include <string>
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenModels/EvtOmegaOmega3pi.hh"
#include "EvtGenBase/EvtDiracSpinor.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtVector4C.hh"

#include "EvtGenBase/EvtComplex.hh"
#include "EvtGenBase/EvtVector4R.hh"
#include "EvtGenBase/EvtVector3R.hh"
#include "EvtGenModels/EvtWHad.hh"

EvtOmegaOmega3pi::~EvtOmegaOmega3pi() {
        f1a = 1; f1b = 1; f1c = 1; f1d = 1;
        f2a = 1; f2b = 1; f2c = 1; f2d = 1;
        g1a = 1; g1b = 1; g1c = 1; g1d = 1;
        g2a = 1; g2b = 1; g2c = 1; g2d = 1;
}

std::string EvtOmegaOmega3pi::getName(){

  return "OMEGAOMEGA3PI";     

}


EvtDecayBase* EvtOmegaOmega3pi::clone(){

  return new EvtOmegaOmega3pi;

}

void EvtOmegaOmega3pi::init(){

  // check that there are 0 arguments
  checkNArg(0);
  checkNDaug(4);

  checkSpinParent(EvtSpinType::DIRAC);

  checkSpinDaughter(0,EvtSpinType::DIRAC);
  checkSpinDaughter(1,EvtSpinType::SCALAR);
  checkSpinDaughter(2,EvtSpinType::SCALAR);
  checkSpinDaughter(3,EvtSpinType::SCALAR);
  
   static EvtId idOmegaccplus = EvtPDL::getId("Omega_cc+");
   static EvtId idOmegaczero = EvtPDL::getId("Omega_c0");
   static EvtId idXiccplus = EvtPDL::getId("Xi_cc+");
   static EvtId idXiczero = EvtPDL::getId("Xi_c0");
   
   EvtId parnum=getParentId();
   EvtId daughtnum = idOmegaczero;
   
        /*f1a = 0; f1b = 0; f1c = 0; f1d = 0;
        f2a = 0; f2b = 0; f2c = 0; f2d = 0;
        g1a = 0; g1b = 0; g1c = 0; g1d = 0;
        g2a = 0; g2b = 0; g2c = 0; g2d = 0;*/
   
        if ( parnum == idOmegaccplus && daughtnum == idOmegaczero){
            f1a = -0.754; f1b = 0.263; f1c = 0.047; f1d = 0.0205;
            f2a = -1.02; f2b = 0.225; f2c = 0.0329; f2d = 0.00381;
            g1a = 1.59; g1b = 0.376; g1c = 0.0926; g1d = 0.0244;
            g2a = 0.119; g2b = 0.671; g2c = 0.297; g2d = -0.159;
        } 
        if (parnum == idXiccplus && daughtnum == idOmegaczero){
            f1a = 0.914; f1b = 0.348; f1c = 0.0818; f1d = 0.0187;
            f2a = 0.0116; f2b = 1.31; f2c = 0.513; f2d = 0.15;
            g1a = 0.258; g1b = 0.208; g1c = 0.0262; g1d = -0.00028;
            g2a = -0.0608; g2b = 0.364; g2c = 0.289; g2d = -0.16;            
        }
  
}

void EvtOmegaOmega3pi::initProbMax(){

  //setProbMax(650.0);

}

void EvtOmegaOmega3pi::HadronicAmp( EvtParticle* parent, 
                                 EvtParticle* child, 
                                 EvtVector4C* T,
                                 const int i, 
                                 const int j )
{
	const EvtDiracSpinor Sfinal = child->spParent(i);
 	const EvtDiracSpinor Sinit  = parent->sp(j);
        const EvtVector4R pp = parent->getP4Lab();
  	const EvtVector4R cp = child->getP4Lab();
        const double pm = parent->mass();
        const double cm = child->mass();
	 // \bar{u} \gamma^{\mu} u
  	T[0] = EvtLeptonVCurrent( Sfinal, Sinit );

  	// \bar{u} \gamma^{\mu}\gamma^{5} u
  	T[1] = EvtLeptonACurrent( Sfinal, Sinit );
  
  	// \bar{u} u
  	T[2] = EvtLeptonSCurrent( Sfinal, Sinit ) * ((pp+cp)/pm);
  
  	// \bar{u} \gamma^{5} u
  	T[3] = EvtLeptonPCurrent( Sfinal, Sinit ) * ((pp+cp)/pm);
  
  	return;
}
const double EvtOmegaOmega3pi::ff(const double f0, const double alpha, const double beta, const double gamma, EvtVector4R qqq){
    return f0*(1 + alpha*qqq*qqq + beta*qqq*qqq*qqq*qqq + gamma*qqq*qqq*qqq*qqq*qqq*qqq);
}
void EvtOmegaOmega3pi::decay(EvtParticle *b1){
  static EvtId TAUM=EvtPDL::getId("tau-");

  b1->initializePhaseSpace(getNDaug(),getDaugs());

  EvtParticle *b2, *pi1, *pi2, *pi3;

	b2=b1->getDaug(0);
  	pi1 = b1->getDaug(1);
  	pi2 = b1->getDaug(2);
        pi3 = b1->getDaug(3); 
        
        EvtVector4R ppi1, ppi2, ppi3; //Импульсы пионов
        ppi1 = pi1 -> getP4Lab();
        ppi2 = pi2 -> getP4Lab();
        ppi3 = pi3 -> getP4Lab();
        

	const EvtVector4R pb1 = b1->getP4Lab();
  	const EvtVector4R pb2 = b2->getP4Lab();
	EvtVector4R q=pb1-pb2;
        const double m1=b1->mass();
        const double m2=b2->mass();

        const double f1 = ff(f1a, f1b, f1c, f1d, q);
        const double f2 = ff(f2a, f2b, f2c, f2d, q);
        const double g1 = ff(g1a, g1b, g1c, g1d, q);
        const double g2 = ff(g2a, g2b, g2c, g2d, q);
	/*const double f1 = ff(-0.754,0.263,0.047,0.0205,q);
	const double g1 = ff(-1.02, 0.225, 0.0329, 0.00381, q);
	const double f2 = ff(1.59, 0.376, 0.0926, 0.0244, q);
	const double g2 = ff(0.119, 0.671, 0.297, -0.159, q);*/
        
	EvtVector4C H[2][2]; // vector current
	EvtVector4C T[6];
    	// Hadronic current
    	for ( int i =0 ; i < 2; ++i ){
       		for ( int j = 0; j < 2; ++j ){
         	HadronicAmp( b1, b2, T, i, j );
         
         	H[i][j] = ( f1*T[0] - g1*T[1] + f2 * T[2] - f2*(m1+m2)/m1*T[0]-g2*T[3] - g2*(m1-m2)/m1*T[1]);
         
       		}
    	}
	//Leptonic current
	EvtWHad qqqqqq = EvtWHad();
	EvtVector4C lep=qqqqqq.WCurrent(ppi1, ppi2, ppi3);
	
	for ( int i =0 ; i < 2; ++i ){
            for ( int j = 0; j < 2; ++j ){
                vertex(i,j, H[i][j]*lep);
            }    
       	}
    	return;
}


 /*   
  EvtVector4C l1, l2, tau1, tau2;

 if (p->getId()==TAUM) {

    tau1=EvtLeptonVACurrent(nut->spParentNeutrino(),p->sp(0));
    tau2=EvtLeptonVACurrent(nut->spParentNeutrino(),p->sp(1));
    l1=EvtLeptonVACurrent(l->spParent(0),nul->spParentNeutrino());
    l2=EvtLeptonVACurrent(l->spParent(1),nul->spParentNeutrino());

  }
  else{
    tau1=EvtLeptonVACurrent(p->sp(0),nut->spParentNeutrino());
    tau2=EvtLeptonVACurrent(p->sp(1),nut->spParentNeutrino());
    l1=EvtLeptonVACurrent(nul->spParentNeutrino(),l->spParent(0));
    l2=EvtLeptonVACurrent(nul->spParentNeutrino(),l->spParent(1));
  }

  vertex(0,0,tau1*l1);
  vertex(0,1,tau1*l2);
  vertex(1,0,tau2*l1);
  vertex(1,1,tau2*l2);
  return;

}*/
