#ifndef STEPPERAXIS_HH
#define STEPPERAXIS_HH

#include "StepperInterface.hh"

/// The stepper axis module implmeents a driver for a single stepper axis. It is designed
/// to be accessed via the Steppers namespace, and uses a StepperInterface to talk to the
/// actual hardware.
/// \ingroup SoftwareLibraries
class StepperAxis
{
public:
        StepperInterface* interface;    ///< Interface this axis is connected to
        volatile int32_t position;      ///< Current position of this axis, in steps
        int32_t minimum;                ///< Minimum position, in steps
        int32_t maximum;                ///< Maximum position, in steps
        volatile int32_t target;        ///< Target position, in steps
        volatile int32_t counter;       ///< Step counter; represents the proportion of
                                        ///< a step so far passed.  When the counter hits
                                        ///< zero, a step is taken.
        volatile int32_t delta;         ///< Amount to increment counter per tick
        volatile bool direction;        ///< True for positive, false for negative

public:
        /// Construct a stepper axis with a null interface
        StepperAxis();

        /// Construct a stepper axis, using the given stepper
        /// interface
        /// \param[in] Stepper interface to use
        StepperAxis(StepperInterface& stepper_interface);

        /// Set the target position for the axis to travel to.
        /// \param[in] target_in Postion to move to, in steps
        /// \param[in] relative If true, consider the target position
        ///                     to be relative to the current position.
        void setTarget(const int32_t target_in, bool relative);

        /// Start a homing procedure
        /// \param[in] direction_in If true, home in the positive direction.
        void setHoming(const bool direction_in);

        /// Reset the axis position to the given position.
        /// \param[in] position_in New axis position
        void definePosition(const int32_t position_in);

        /// Set whether the stepper motor driver on the given axis should be enabled
        /// \param[in] enable If true, enable the axis; otherwise, disable it.
        void enableStepper(bool enable);

        /// Reset to initial state
        void reset();

        /// Handle interrupt for the given axis.
        /// \param[in] intervals Intervals that have passed since the previous interrupt
        void doInterrupt(const int32_t intervals);

        /// Run the next step of the homing procedure.
        /// \param[in] intervals Intervals that have passed since the previous interrupt
        /// \return True if the axis is still homing.
        bool doHoming(const int32_t intervals);
};

#endif // STEPPERAXIS_HH
