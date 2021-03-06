#ifndef __SKID_STEER_CONTROL_BASED_HH__
#define __SKID_STEER_CONTROL_BASED_HH__

#include "RobotModel.hh"
#include "MathFunctions.hh"

#include <fstream>
#include <cstdlib>

// Forward Declaration
class TrackingControl;

class SkidSteerControlBased : public RobotModel
{
    public:
        SkidSteerControlBased(double *, double *, int);
        void SetPDTrajectoryControl(void);
        void SetFierroTrajectoryControl(void);
        void EstimateNewState(const double *, const double *, double *);
        void dflow(const double *, const double *, double *);
        void EstimatePosition(const double *, const double *, double *);
        void velocities_dflow(const double *, const double *, double *);
        void EstimateVelocities(const double *,
                                const double *, double *);
        void GenerateInputs(char *);
        void GetValidInputs(const double *x);
        void EstimateTorque(const double *, const double *, double *);
        bool VerifyFeasibility(const double *x, const double *u);
        void EstimateVelocitiesFromTorque(const double*, const double*, double*);
        double GetXCIR(void);
        ~SkidSteerControlBased();
        TrackingControl *trajectory_control;
    private:
        double Inertia, mass, fr, mu, xcir, a, b, c, wheel_radius, torque_max,
               max_v, max_w;
        
        vector<control_input> all_inputs;
};

#endif
