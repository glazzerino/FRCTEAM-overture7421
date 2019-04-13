#include "frc/Encoder.h"
#include "Subsystems/FluxSubsystem.h"
#include "Subsystems/Datapool.h"
using namespace frc;
class Odometry : public FluxSubsystem {
    public:
        Odometry();
        void robotInit() override;
        void robotUpdate() override;
        void teleopInit() override;
        void teleopUpdate() override;
        void autonInit() override;
        void autonUpdate() override;
        void disabledInit() override;
        void disabledUpdate() override;
    private:
        Encoder leftEnc{1,2};
        Encoder rightEnc{3,4};
}


