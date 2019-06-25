// test
#include "EvtGenBase/EvtPatches.hh"
#include <stdlib.h>
#include <iostream>
#include <string>
#include "EvtGenBase/EvtParticle.hh"
#include "EvtGenBase/EvtPDL.hh"
#include "EvtGenBase/EvtGenKine.hh"
#include "EvtGenModels/EvtOmegaOmega.hh"
#include "EvtGenBase/EvtDiracSpinor.hh"
#include "EvtGenBase/EvtReport.hh"
#include "EvtGenBase/EvtVector4C.hh"

#include "EvtGenBase/EvtComplex.hh"
#include "EvtGenBase/EvtVector4R.hh"
#include "EvtGenBase/EvtVector3R.hh"
#include "EvtGenModels/EvtWHad.hh"

EvtOmegaOmega::~EvtOmegaOmega() {
    f1a = 1;
    f1b = 1;
    f1c = 1;
    f1d = 1;
    f2a = 1;
    f2b = 1;
    f2c = 1;
    f2d = 1;
    g1a = 1;
    g1b = 1;
    g1c = 1;
    g1d = 1;
    g2a = 1;
    g2b = 1;
    g2c = 1;
    g2d = 1;
}

std::string EvtOmegaOmega::getName() {

    return "OMEGAOMEGA";

}

EvtDecayBase* EvtOmegaOmega::clone() {

    return new EvtOmegaOmega;

}

void EvtOmegaOmega::init() {

    // check that there are 0 arguments
    checkNArg(0);
    //checkNDaug(3);

    checkSpinParent(EvtSpinType::DIRAC);

    //checkSpinDaughter(0, EvtSpinType::DIRAC);
    //checkSpinDaughter(1, EvtSpinType::DIRAC);
    //checkSpinDaughter(2, EvtSpinType::NEUTRINO);

    EvtId parnum = getParentId();
    EvtId daughtnum = getDaug(0);
    
    

    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum == EvtPDL::getId("Lambda_c+")) {
        //    \Xi_{cc}^{++}\Lambda_{c}^{+}
        f1a = 0.790517;
        f1b = 0.386325;
        f1c = 0.118192;
        f1d = 0.015972;
        f2a = -0.00793954;
        f2b = -0.481435;
        f2c = -0.404882;
        f2d = -0.199791;
        g1a = 0.224199;
        g1b = 0.234646;
        g1c = 0.0386314;
        g1d = -0.00450002;
        g2a = -0.0481814;
        g2b = 0.844711;
        g2c = -1.13974;
        g2d = 0.29521;
    }

    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum == EvtPDL::getId("Sigma_c+")) {
        // \Xi_{cc}^{++}\Sigma_{c}^{+}
        f1a = -0.46708;
        f1b = 0.293748;
        f1c = 0.0330672;
        f1d = 0.0416906;
        f2a = 1.04033;
        f2b = 0.417692;
        f2c = 0.107752;
        f2d = 0.037023;
        g1a = -0.624378;
        g1b = 0.24355;
        g1c = 0.0377786;
        g1d = 0.00398585;
        g2a = 0.0446598;
        g2b = 1.60765;
        g2c = -1.68187;
        g2d = 0.321318;
    }

    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum == EvtPDL::getId("Xi_c+")) {
        // \Xi_{cc}^{++}\Xi_{c}^{+}
        f1a = 0.914249;
        f1b = 0.347935;
        f1c = 0.0817908;
        f1d = 0.0186894;
        f2a = 0.0116363;
        f2b = 1.307;
        f2c = 0.512884;
        f2d = 0.149521;
        g1a = 0.258429;
        g1b = 0.208055;
        g1c = 0.0262441;
        g1d = -0.000279583;
        g2a = -0.0608048;
        g2b = 0.364131;
        g2c = 0.288789;
        g2d = -0.160034;
    }

    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum == EvtPDL::getId("Xi'_c+")) {
        //\Xi_{cc}^{++}\Xi_{c}^{\prime+}
        f1a = -0.538392;
        f1b = 0.2467;
        f1c = 0.0383669;
        f1d = 0.0213286;
        f2a = 1.11395;
        f2b = 0.365881;
        f2c = 0.0862851;
        f2d = 0.027594;
        g1a = -0.727609;
        g1b = 0.215622;
        g1c = 0.0305195;
        g1d = 0.00385625;
        g2a = 0.0782858;
        g2b = 0.648581;
        g2c = 0.330611;
        g2d = -0.187028;
    }

    if (parnum == EvtPDL::getId("Xi_cc+") && daughtnum == EvtPDL::getId("Sigma_c0")) {
  //      \Xi_{cc}^{+}\Sigma_{c}^{0}
        f1a = -0.660555;
        f1b = 0.293679;
        f1c = 0.0332159;
        f1d = 0.0416061;
        f2a = 1.47125;
        f2b = 0.417682;
        f2c = 0.107772;
        f2d = 0.0370116;
        g1a = -0.883003;
        g1b = 0.243551;
        g1c = 0.0377772;
        g1d = 0.00398665;
        g2a = 0.0631693;
        g2b = 1.60542;
        g2c = -1.67728;
        g2d = 0.318823;
    }


    if (parnum == EvtPDL::getId("Xi_cc+") && daughtnum == EvtPDL::getId("Xi'_c0")) {
        // \Xi_{cc}^{+}\Xi_{c}^{\prime0}
        f1a = -0.538393;
        f1b = 0.246683;
        f1c = 0.0384136;
        f1d = 0.0212954;
        f2a = 1.11395;
        f2b = 0.365871;
        f2c = 0.0863111;
        f2d = 0.0275755;
        g1a = -0.727609;
        g1b = 0.215621;
        g1c = 0.0305209;
        g1d = 0.00385526;
        g2a = 0.0782847;
        g2b = 0.648806;
        g2c = 0.330022;
        g2d = -0.18661;
    }


    if (parnum == EvtPDL::getId("Omega_cc+") && daughtnum == EvtPDL::getId("Xi_c0")) {
        // \Omega_{cc}^{+}\Xi_{c}^{0}
        f1a = -0.782742;
        f1b = 0.405696;
        f1c = 0.11675;
        f1d = 0.0190916;
        f2a = 0.0214305;
        f2b = 0.194011;
        f2c = -0.0126728;
        f2d = -0.0213818;
        g1a = -0.22231;
        g1b = 0.248891;
        g1c = 0.0375397;
        g1d = -0.00273119;
        g2a = 0.0535492;
        g2b = 0.732906;
        g2c = -0.77817;
        g2d = 0.103429;
    }


    if (parnum == EvtPDL::getId("Omega_cc+") && daughtnum == EvtPDL::getId("Xi'_c0")) {
        //\Omega_{cc}^{+}\Xi_{c}^{\prime0}
        f1a = -0.461591;
        f1b = 0.30751;
        f1c = 0.0495384;
        f1d = 0.0408374;
        f2a = 1.05106;
        f2b = 0.425475;
        f2c = 0.115872;
        f2d = 0.0334016;
        g1a = -0.618371;
        g1b = 0.252841;
        g1c = 0.0397874;
        g1d = 0.00308026;
        g2a = 0.0510923;
        g2b = 1.29652;
        g2c = -0.873672;
        g2d = -0.132622;
    }
    
    if (parnum == EvtPDL::getId("Omega_cc+") && daughtnum == EvtPDL::getId("Omega_c0")) {
        f1a = -0.754457;
        f1b = 0.262634;
        f1c = 0.047046;
        f1d = 0.0205154;
        f2a = 1.59496;
        f2b = 0.375924;
        f2c = 0.0926231;
        f2d = 0.0244409;
        g1a = -1.0205;
        g1b = 0.225275;
        g1c = 0.0329067;
        g1d = 0.00381334;
        g2a = 0.118609;
        g2b = 0.671027;
        g2c = 0.296942;
        g2d = -0.159121;
    }
    else 
        if (parnum == EvtPDL::getId("Xi_cc+") && daughtnum == EvtPDL::getId("Xi_c0")) {
            f1a = 0.914;
            f1b = 0.348;
            f1c = 0.0818;
            f1d = 0.0187;
            f2a = 0.0116;
            f2b = 1.31;
            f2c = 0.513;
            f2d = 0.15;
            g1a = 0.258;
            g1b = 0.208;
            g1c = 0.0262;
            g1d = -0.00028;
            g2a = -0.0608;
            g2b = 0.364;
            g2c = 0.289;
            g2d = -0.16;
        } else {
            std::cout << "Wrong baryons\n";
        }
    
}

void EvtOmegaOmega::initProbMax() {
    EvtId parnum = getParentId();
    EvtId daughtnum1 = getDaug(0);
    EvtId daughtnum2 = getDaug(1);
    EvtId daughtnum3 = getDaug(2);
    size_t n = getNDaug();
    
    if (n==3) //l nul case
    {
    if (parnum == EvtPDL::getId("Omega_cc+") && daughtnum1 == EvtPDL::getId("Omega_c0") && (daughtnum2 == EvtPDL::getId("e-") || daughtnum2 == EvtPDL::getId("e+") )  ) {
        setProbMax(9000.0);
    }
    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum1 == EvtPDL::getId("Lambda_c+")) {
        //    \Xi_{cc}^{++}\Lambda_{c}^{+}
        //setProbMax(9000.0);
    }

    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum1 == EvtPDL::getId("Sigma_c+")) {
        // \Xi_{cc}^{++}\Sigma_{c}^{+}
        //setProbMax(9000.0);
    }

    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum1 == EvtPDL::getId("Xi_c+")) {
        // \Xi_{cc}^{++}\Xi_{c}^{+}
        //setProbMax(9000.0);
    }

    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum1 == EvtPDL::getId("Xi'_c+")) {
        //\Xi_{cc}^{++}\Xi_{c}^{\prime+}
        //setProbMax(9000.0);
    }

    if (parnum == EvtPDL::getId("Xi_cc+") && daughtnum1 == EvtPDL::getId("Sigma_c0")) {
  //      \Xi_{cc}^{+}\Sigma_{c}^{0}
        //setProbMax(9000.0);
    }


    if (parnum == EvtPDL::getId("Xi_cc+") && daughtnum1 == EvtPDL::getId("Xi'_c0")) {
        // \Xi_{cc}^{+}\Xi_{c}^{\prime0}
        //setProbMax(9000.0);
    }


    if (parnum == EvtPDL::getId("Omega_cc+") && daughtnum1 == EvtPDL::getId("Xi_c0")) {
        // \Omega_{cc}^{+}\Xi_{c}^{0}
        //setProbMax(9000.0);
    }


    if (parnum == EvtPDL::getId("Omega_cc+") && daughtnum1 == EvtPDL::getId("Xi'_c0")) {
        //\Omega_{cc}^{+}\Xi_{c}^{\prime0}
        //setProbMax(9000.0);
    }
    
    if (parnum == EvtPDL::getId("Xi_cc+") && daughtnum1== EvtPDL::getId("Xi_c0")) {
        //setProbMax(9000.0);
    }
    }
    if (n==4) //3pi case
    {
    if (parnum == EvtPDL::getId("Omega_cc+") && daughtnum1 == EvtPDL::getId("Omega_c0") && (daughtnum2 == EvtPDL::getId("e-") || daughtnum2 == EvtPDL::getId("e+") )  ) {
 //       setProbMax(9000.0);
    }
    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum1 == EvtPDL::getId("Lambda_c+")) {
        //    \Xi_{cc}^{++}\Lambda_{c}^{+}
        //setProbMax(9000.0);
    }

    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum1 == EvtPDL::getId("Sigma_c+")) {
        // \Xi_{cc}^{++}\Sigma_{c}^{+}
        //setProbMax(9000.0);
    }

    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum1 == EvtPDL::getId("Xi_c+")) {
        // \Xi_{cc}^{++}\Xi_{c}^{+}
        //setProbMax(9000.0);
    }

    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum1 == EvtPDL::getId("Xi'_c+")) {
        //\Xi_{cc}^{++}\Xi_{c}^{\prime+}
        //setProbMax(9000.0);
    }

    if (parnum == EvtPDL::getId("Xi_cc+") && daughtnum1 == EvtPDL::getId("Sigma_c0")) {
  //      \Xi_{cc}^{+}\Sigma_{c}^{0}
        //setProbMax(9000.0);
    }


    if (parnum == EvtPDL::getId("Xi_cc+") && daughtnum1 == EvtPDL::getId("Xi'_c0")) {
        // \Xi_{cc}^{+}\Xi_{c}^{\prime0}
        //setProbMax(9000.0);
    }


    if (parnum == EvtPDL::getId("Omega_cc+") && daughtnum1 == EvtPDL::getId("Xi_c0")) {
        // \Omega_{cc}^{+}\Xi_{c}^{0}
        //setProbMax(9000.0);
    }


    if (parnum == EvtPDL::getId("Omega_cc+") && daughtnum1 == EvtPDL::getId("Xi'_c0")) {
        //\Omega_{cc}^{+}\Xi_{c}^{\prime0}
        //setProbMax(9000.0);
    }
    
    if (parnum == EvtPDL::getId("Xi_cc+") && daughtnum1== EvtPDL::getId("Xi_c0")) {
        //setProbMax(9000.0);
    }
    }
    if (n==6) //5pi case
    {
    if (parnum == EvtPDL::getId("Omega_cc+") && daughtnum1 == EvtPDL::getId("Omega_c0") && (daughtnum2 == EvtPDL::getId("e-") || daughtnum2 == EvtPDL::getId("e+") )  ) {
//        setProbMax(9000.0);
    }
    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum1 == EvtPDL::getId("Lambda_c+")) {
        //    \Xi_{cc}^{++}\Lambda_{c}^{+}
        //setProbMax(9000.0);
    }

    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum1 == EvtPDL::getId("Sigma_c+")) {
        // \Xi_{cc}^{++}\Sigma_{c}^{+}
        //setProbMax(9000.0);
    }

    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum1 == EvtPDL::getId("Xi_c+")) {
        // \Xi_{cc}^{++}\Xi_{c}^{+}
        //setProbMax(9000.0);
    }

    if (parnum == EvtPDL::getId("Xi_cc++") && daughtnum1 == EvtPDL::getId("Xi'_c+")) {
        //\Xi_{cc}^{++}\Xi_{c}^{\prime+}
        //setProbMax(9000.0);
    }

    if (parnum == EvtPDL::getId("Xi_cc+") && daughtnum1 == EvtPDL::getId("Sigma_c0")) {
  //      \Xi_{cc}^{+}\Sigma_{c}^{0}
        //setProbMax(9000.0);
    }


    if (parnum == EvtPDL::getId("Xi_cc+") && daughtnum1 == EvtPDL::getId("Xi'_c0")) {
        // \Xi_{cc}^{+}\Xi_{c}^{\prime0}
        //setProbMax(9000.0);
    }


    if (parnum == EvtPDL::getId("Omega_cc+") && daughtnum1 == EvtPDL::getId("Xi_c0")) {
        // \Omega_{cc}^{+}\Xi_{c}^{0}
        //setProbMax(9000.0);
    }


    if (parnum == EvtPDL::getId("Omega_cc+") && daughtnum1 == EvtPDL::getId("Xi'_c0")) {
        //\Omega_{cc}^{+}\Xi_{c}^{\prime0}
        //setProbMax(9000.0);
    }
    
    if (parnum == EvtPDL::getId("Xi_cc+") && daughtnum1== EvtPDL::getId("Xi_c0")) {
        //setProbMax(9000.0);
    }
    }
    

}

void EvtOmegaOmega::HadronicAmp(EvtParticle* parent,
        EvtParticle* child,
        EvtVector4C* T,
        const int i,
        const int j) {
    const EvtDiracSpinor Sfinal = child->spParent(i);
    const EvtDiracSpinor Sinit = parent->sp(j);
    const EvtVector4R pp = parent->getP4Lab();
    const EvtVector4R cp = child->getP4Lab();
    const double pm = parent->mass();
    const double cm = child->mass();
    // \bar{u} \gamma^{\mu} u
    T[0] = EvtLeptonVCurrent(Sfinal, Sinit);

    // \bar{u} \gamma^{\mu}\gamma^{5} u
    T[1] = EvtLeptonACurrent(Sfinal, Sinit);

    // \bar{u} u
    T[2] = EvtLeptonSCurrent(Sfinal, Sinit) * ((pp + cp) / pm);

    // \bar{u} \gamma^{5} u
    T[3] = EvtLeptonPCurrent(Sfinal, Sinit) * ((pp + cp) / pm);

    return;
}

const double EvtOmegaOmega::ff(const double f0, const double alpha, const double beta, const double gamma, EvtVector4R qqq) {
    return f0 * (1 + alpha * qqq * qqq + beta * qqq * qqq * qqq * qqq + gamma * qqq * qqq * qqq * qqq * qqq * qqq);
}

void EvtOmegaOmega::decay(EvtParticle *b1) {
    static EvtId TAUM = EvtPDL::getId("tau-");

    b1->initializePhaseSpace(getNDaug(), getDaugs());

    EvtParticle *b2;
    b2 = b1->getDaug(0);
    
    

    const EvtVector4R pb1 = b1->getP4Lab();
    const EvtVector4R pb2 = b2->getP4Lab();
    EvtVector4R q = pb1 - pb2;
    const double m1 = b1->mass();
    const double m2 = b2->mass();


    const double f1 = ff(f1a, f1b, f1c, f1d, q);
    const double f2 = ff(f2a, f2b, f2c, f2d, q);
    const double g1 = ff(g1a, g1b, g1c, g1d, q);
    const double g2 = ff(g2a, g2b, g2c, g2d, q);
   
    EvtVector4C H[2][2]; // vector current
    EvtVector4C T[6];
    // Hadronic current
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            HadronicAmp(b1, b2, T, i, j);

            H[i][j] = (f1 * T[0] - g1 * T[1] + f2 * T[2] - f2 * (m1 + m2) / m1 * T[0] - g2 * T[3] - g2 * (m1 - m2) / m1 * T[1]);

        }
    }
    EvtId check1 = getDaug(1);
    
    
       EvtParticle  *l, *nul;    
    l = b1->getDaug(1);
    nul = b1->getDaug(2);
    //Leptonic current
    EvtVector4C lep[2];
    lep[0] = EvtLeptonVACurrent(l->spParent(0), nul->spParentNeutrino());
    lep[1] = EvtLeptonVACurrent(l->spParent(1), nul->spParentNeutrino());

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                vertex(i, j, k, H[i][j] * lep[k]);
            }
        }
    }
    
    //l nu_l case
    if (check1==EvtPDL::getId("e+") || check1==EvtPDL::getId("e-")){
/*    EvtParticle  *l, *nul;    
    l = b1->getDaug(1);
    nul = b1->getDaug(2);
    //Leptonic current
    EvtVector4C lep[2];
    lep[0] = EvtLeptonVACurrent(l->spParent(0), nul->spParentNeutrino());
    lep[1] = EvtLeptonVACurrent(l->spParent(1), nul->spParentNeutrino());

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                vertex(i, j, k, H[i][j] * lep[k]);
            }
        }
    }*/
    }
        //3pi case
        if(getNDaug()==4){
            EvtParticle *pi1, *pi2, *pi3;

            pi1 = b1->getDaug(1);
            pi2 = b1->getDaug(2);
            pi3 = b1->getDaug(3); 
            
            EvtVector4R ppi1, ppi2, ppi3; //Импульсы пионов
            ppi1 = pi1 -> getP4Lab();
            ppi2 = pi2 -> getP4Lab();
            ppi3 = pi3 -> getP4Lab();
            EvtWHad qqqqqq = EvtWHad();
            EvtVector4C lep=qqqqqq.WCurrent(ppi1, ppi2, ppi3);
	
            for ( int i =0 ; i < 2; ++i ){
                for ( int j = 0; j < 2; ++j ){
                    vertex(i,j, H[i][j]*lep);
                }    
            }
        }
            //5pi case
            if(getNDaug()==6){
                EvtParticle *pi1, *pi2, *pi3, *pi4, *pi5;
                pi1 = b1->getDaug(1);
                pi2 = b1->getDaug(2);
                pi3 = b1->getDaug(3); 
                pi4 = b1->getDaug(4); 
                pi5 = b1->getDaug(5); 
                EvtVector4R ppi1, ppi2, ppi3, ppi4, ppi5; //Импульсы пионов
                ppi1 = pi1 -> getP4Lab();
                ppi2 = pi2 -> getP4Lab();
                ppi3 = pi3 -> getP4Lab();
                ppi4 = pi4 -> getP4Lab();
                ppi5 = pi5 -> getP4Lab();
                EvtWHad qqqqqqq = EvtWHad();
                EvtVector4C lep=qqqqqqq.WCurrent(ppi1, ppi2, ppi3, ppi4, ppi5);
                for ( int i =0 ; i < 2; ++i ){
                    for ( int j = 0; j < 2; ++j ){
                        vertex(i,j, H[i][j]*lep);
                    }    
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
