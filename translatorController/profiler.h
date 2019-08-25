#ifndef __PROFILER__
#define __PROFILER__

class Profiler
{
    enum class State { ride, end, breaking };
    State state_ { State::ride };
    float targetSpeed_ { 0 };
    float speedInNextStep_ { 0 };
    float currentSpeed_ { 0 };
    float acceleration_ { 0 };
    int totalRoadToPass_ { 0 };
    int passedRoad_ { 0 };

    public:
    Profiler(int acc , int target ):
        acceleration_( acc ),
        targetSpeed_( target ){};
    void calculate();
    int getNextStepValue();
    bool isEndOfRoad();
    
    private:
    bool isNecessaryToBrake();
    int calculateNextStepSeed() = 0;
    bool isReachedHisDestination();
};

#endif