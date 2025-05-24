#include "Context.hpp"
#include "Command.hpp"
#include "States/Observer.hpp"
#include "States/Strategy.hpp"
#include "States/IdleState.hpp"

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    Context ctx(&IdleState::instance());
    Logger logger;
    ctx.addObserver(&logger);
    ctx.setStrategy(std::make_unique<SequentialStrategy>());

    StartCommand start;
    start.execute(ctx);
    ctx.executeStrategy();

    PauseCommand pause;
    pause.execute(ctx);

    ResumeCommand resume;
    resume.execute(ctx);
    ctx.executeStrategy();

    CompleteCommand complete;
    complete.execute(ctx);

    ResetCommand reset;
    reset.execute(ctx);

    start.execute(ctx);
    ctx.executeStrategy();

    ErrorCommand error;
    error.execute(ctx);

    reset.execute(ctx);

    return 0;
}