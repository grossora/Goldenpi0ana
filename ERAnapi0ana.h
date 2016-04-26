/**
 * \file ERAnapi0ana.h
 *
 * \ingroup GoldenPi0
 * 
 * \brief Class def header for a class ERAnapi0ana
 *
 * @author ryan
 */

/** \addtogroup GoldenPi0

    @{*/

#ifndef ERTOOL_ERANAPI0ANA_H
#define ERTOOL_ERANAPI0ANA_H

#include "ERTool/Base/AnaBase.h"
#include "ERTool/Base/ParticleGraph.h"
#include "ERTool/Base/Particle.h"
#include "ERTool/Base/EventData.h"

#include "TTree.h"
#include "TH2.h"


namespace ertool {

  /**
     \class ERAnapi0ana
     User custom Analysis class made by kazuhiro
   */
  class ERAnapi0ana : public AnaBase {
  
  public:

    /// Default constructor
    ERAnapi0ana(const std::string& name="ERAnapi0ana");

    /// Default destructor
    virtual ~ERAnapi0ana(){}

    /// Reset function
    virtual void Reset();

    /// Function to accept fclite::PSet
    void AcceptPSet(const ::fcllite::PSet& cfg);

    /// Called @ before processing the first event sample
    void ProcessBegin();

    /// Function to evaluate input showers and determine a score
    bool Analyze(const EventData &data, const ParticleGraph &graph);

    /// Called after processing the last event sample
    void ProcessEnd(TFile* fout=nullptr);

   private: 

//Fit params
//
	// First correct the sqrt(ee) with simple linear fit
	// These can be put into a paramter file later on for a given reconstruction
	// sqrt(EE)_fit = sqrt(\alpha)*sqrt(EE_reco)
	// sqrt(\alpha) = E_M * sqrt(EE) + P1
	double E_M= -999;
	double P1= -999;
	
//

	// fitfunctions
	

	
	TTree* _mctree;
	double _pi0_x;
	double _pi0_y;
	double _pi0_z;
	double _pi0_p;
	double _pi0_px;
	double _pi0_py;
	double _pi0_pz;
	double _g1_x;
	double _g1_y;
	double _g1_z;
	double _g1_p;
	double _g1_px;
	double _g1_py;
	double _g1_pz;
	double _g2_x;
	double _g2_y;
	double _g2_z;
	double _g2_p;
	double _g2_px;
	double _g2_py;
	double _g2_pz;
	double _g1g2_p;
	double _g1g2_angle;
	double _g1dep_x;
	double _g1dep_y;
	double _g1dep_z;
	double _g1dep_p;
	double _g1dep_px;
	double _g1dep_py;
	double _g1dep_pz;
	double _g2dep_x;
	double _g2dep_y;
	double _g2dep_z;
	double _g2dep_p;
	double _g2dep_px;
	double _g2dep_py;
	double _g2dep_pz;
	double _g1g2dep_p;
	double _g1g2dep_angle;



	TTree* _fulltree;
	double _rpi0_x;
	double _rpi0_y;
	double _rpi0_z;
	double _rpi0_p;
	double _rpi0_px;
	double _rpi0_py;
	double _rpi0_pz;
	double _rg1_x;
	double _rg1_y;
	double _rg1_z;
	double _rg1_p;
	double _rg1_px;
	double _rg1_py;
	double _rg1_pz;
	double _rg2_x;
	double _rg2_y;
	double _rg2_z;
	double _rg2_p;
	double _rg2_px;
	double _rg2_py;
	double _rg2_pz;
	double _rg1rg2_p;
	double _rg1rg2_angle;
	double _rg1dep_x;
	double _rg1dep_y;
	double _rg1dep_z;
	double _rg1dep_p;
	double _rg1dep_px;
	double _rg1dep_py;
	double _rg1dep_pz;
	double _rg2dep_x;
	double _rg2dep_y;
	double _rg2dep_z;
	double _rg2dep_p;
	double _rg2dep_px;
	double _rg2dep_py;
	double _rg2dep_pz;
	double _rg1rg2dep_p;
	double _rg1rg2dep_angle;

	// perm histos
	TH1D* _recomass;
	TH1D* _fitrecomass;
	TH1D* _emres;
	TH1D* _angleres;
	TH1D* _emresdep;
	TH1D* _angleresdep;

  };
}
#endif

/** @} */ // end of doxygen group 
