/**
 * \file ERAnaEventdata.h
 *
 * \ingroup Goldenpi0ana
 * 
 * \brief Class def header for a class ERAnaEventdata
 *
 * @author ryan
 */

/** \addtogroup Goldenpi0ana

    @{*/

#ifndef ERTOOL_ERANAEVENTDATA_H
#define ERTOOL_ERANAEVENTDATA_H

#include "ERTool/Base/AnaBase.h"
#include "TTree.h"
#include <array>


namespace ertool {

  /**
     \class ERAnaEventdata
     User custom Analysis class made by kazuhiro
   */
  class ERAnaEventdata : public AnaBase {
  
  public:

    /// Default constructor
    ERAnaEventdata(const std::string& name="ERAnaEventdata");

    /// Default destructor
    virtual ~ERAnaEventdata(){}

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

	TTree* _edtree;
	int _eventid;
	int _run;
	int _subrun;
	int _nshowers;
	// not robust but who cares
	std::array<double,50> _Eshr;
	double _SPshr[50][3];
	double _Dirshr[50][3];
//	std::array<std::array<double,3>,50> _SPshr;
	//std::array<std::array<double,3>,50> _SPshr;
//	std::array<double,3> _EPshr;
	//std::array<std::array<double,3>,50> _Dirshr;

  };
}
#endif

/** @} */ // end of doxygen group 
