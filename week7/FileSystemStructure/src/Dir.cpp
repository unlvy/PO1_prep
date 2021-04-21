#include "Dir.h"

Dir::Dir(std::string name) : FileSystemBase(name, "DIR") {}

Dir* Dir::findDir(std::string name) const {
    for (auto* subElement : m_subElements) {
        if (subElement->getType() == "DIR") {
            if (subElement->getName() == name) {
                return dynamic_cast<Dir*>(subElement);
            } 
            Dir* result =  dynamic_cast<Dir*>(subElement)->findDir(name);
            if (result != nullptr) {
                return result;
            }
        } 
    }
    return nullptr;
}

void Dir::add(Dir* dir) {
    (*this) += dir;
}
