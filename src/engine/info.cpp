#include "info.hpp"

namespace maat{
namespace info{
 
std::ostream& operator<<(std::ostream& os, const MemAccess& mem_access)
{
    std::string space("    ");

    if (mem_access.written and not mem_access.read)
        os << "Memory writen:\n";
    else if (mem_access.read and not mem_access.written)
        os << "Memory read:\n";
    else
        os << "Memory read & written:\n";

    os << space << "Addr: " << mem_access.addr << "\n";
    os << space << "Size: " << mem_access.size << " (bytes)\n";
    if (mem_access.old_value)
        os << space << "Old value:" << mem_access.old_value << "\n";
    if (mem_access.written and mem_access.new_value)
        os << space << "New value " << mem_access.new_value << "\n";
    
    return os;
} 

/// Print branch info to a stream
std::ostream& operator<<(std::ostream& os, const Branch& branch)
{
    std::string space("    ");
    
    os << "Branch:\n";
    if (branch.taken.has_value())
    {
        os << space << "Taken: ";
        if (branch.taken.value())
            os << "Yes\n";
        else
            os << "No\n";
    }
    if (branch.cond)
        os << space << "Condition: " << branch.cond << "\n";
    os << space << "Target: " << branch.target << "\n";
    if (branch.next)
        os << space << "Next: " << branch.next << "\n";
    
    return os;
}

}
}
