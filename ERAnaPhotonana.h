/**
 * \file ERAnaPhotonana.h
 *
 * \ingroup Goldenpi0ana
 * 
 * \brief Class def header for a class ERAnaPhotonana
 *
 * @author ryan
 */

/** \addtogroup Goldenpi0ana

    @{*/

#ifndef ERTOOL_ERANAPHOTONANA_H
#define ERTOOL_ERANAPHOTONANA_H

#include "ERTool/Base/AnaBase.h"
#include "TTree.h"
#include "TH1D.h"
#include "TH2D.h"

namespace ertool {

  /**
     \class ERAnaPhotonana
     User custom Analysis class made by kazuhiro
   */
  class ERAnaPhotonana : public AnaBase {
  
  public:

    /// Default constructor
    ERAnaPhotonana(const std::string& name="ERAnaPhotonana");

    /// Default destructor
    virtual ~ERAnaPhotonana(){}

    /// Reset function
    virtual void Reset();

    /// Function to accept fclite::PSet
    void AcceptPSet(const ::fcllite::PSet& cfg);

    /// Called @ before processing the first event sample
    void ProcessBegin();

    /// Function to evaluate input showers and determine a score
    bool Analyze(const EventData &data, const ParticleGraph &ps);

    /// Called after processing the last event sample
    void ProcessEnd(TFile* fout=nullptr);

	private: 
	int counter=0;	

	TTree* _showertree;
	double _energy = 0;
	double _energydep = 0;
	double _x = -999;
	double _y = -999;
	double _z = -999;
	double _px = -999;
	double _py = -999;
	double _pz = -999;
	double _xdep = -999;
	double _ydep = -999;
	double _zdep = -999;
	double _pxdep = -999;
	double _pydep = -999;
	double _pzdep = -999;
	int _nshowers = -999;
	double _renergy = 0;
	double _rx = -999;
	double _ry = -999;
	double _rz = -999;
	double _rpx = -999;
	double _rpy = -999;
	double _rpz = -999;

	TH2D* _Edepresnshowers;
	TH1D* _Edepres;

  };
}
#endif

/** @} */ // end of doxygen group 
