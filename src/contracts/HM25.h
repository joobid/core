using namespace QPI;

struct HM252
{
};

struct HM25 : public ContractBase
{
public:

    struct SetMilestone_input {};
    struct SetMilestone_output
    {
        uint64 lastMilestone;
    };

    struct GetMilestone_input {};
    struct GetMilestone_output
    {
        uint64 lastMilestone;
    };

    struct GetBudget_input {};
    struct GetBudget_output
    {
        uint64 budget;
    };

private:
    uint64 lastMilestone;
    uint64 budget;

    /**
    Send back the invocation amount
    
    PUBLIC_PROCEDURE(PayBudget)
        if (qpi.invocationReward() > 0)
        {
            state.budget = state.budget - qpi.invocationReward;
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
        }
    */
    _

    _

    PUBLIC_FUNCTION(SetMilestone)
        state.lastMilestone = output.lastMilestone;

    PUBLIC_FUNCTION(GetMilestone)
        output.lastMilestone = state.lastMilestone;

    PUBLIC_FUNCTION(GetBudget)
        output.budget = state.budget;
    _

    REGISTER_USER_FUNCTIONS_AND_PROCEDURES

        /* REGISTER_USER_PROCEDURE(PayBudget, 1); */

        REGISTER_USER_FUNCTION(SetMilestone, 1);
        REGISTER_USER_FUNCTION(GetMilestone, 2);
        REGISTER_USER_FUNCTION(GetBudget, 3);
    _

    INITIALIZE
        state.lastMilestone = 0;
        state.budget = 1000;
    _
};
