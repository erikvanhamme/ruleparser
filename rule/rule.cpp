#include "action/action.hpp"
#include "condition/condition.hpp"
#include "rule.hpp"
#include <memory>
#include <string>

namespace wf
{

class rule_interface_t;

rule_t::rule_t(const std::string &signal,
               std::shared_ptr<condition_t> condition,
               std::shared_ptr<action_t> if_action,
               std::shared_ptr<action_t> else_action) :
    _signal(signal),
    _condition(condition),
    _if_action(if_action),
    _else_action(else_action)
{
}

bool rule_t::apply(const std::string &signal, rule_interface_t &interface)
{
    if ((signal.empty()) || (_condition == nullptr) || (_if_action == nullptr))
    {
        return true;
    }

    bool error = false;
    if (signal == _signal)
    {
        auto check_result = _condition->evaluate(interface, error);
        if (!error)
        {
            if (check_result)
            {
                error = _if_action->execute(interface);
            }
            else
            {
                if (_else_action != nullptr)
                {
                    error = _else_action->execute(interface);
                }
            }
        }
    }

    return error;
}

} // End namespace wf.
