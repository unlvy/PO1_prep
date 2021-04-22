#include "FileSystemBase.h"

std::ostream& operator<< (std::ostream& os, const FileSystemBase& f) {
    os << f.toString();
    return os;
}

FileSystemBase::FileSystemBase(std::string name, std::string type) : m_name(name), m_type(type) {}

FileSystemBase::~FileSystemBase() {
    if (m_type == "DIR") {
        std::cout << "Deleting " << "Dir: " << m_name << std::endl;
    }
    for (auto* subElement : m_subElements) {
        std::cout << "About to delete " << subElement->getName() << std::endl;
        delete subElement;
    }
}

std::string FileSystemBase::getName() const {
    return m_name;
}

std::string FileSystemBase::getType() const {
    return m_type;
}

void FileSystemBase::operator+= (FileSystemBase* subElement) {
    m_subElements.push_back(subElement);
}

std::string FileSystemBase::toString(int spaces) const {
    std::string result = "";
    for (int i = 0; i < spaces; i++) {
        result += " ";
    }
    result += m_name + " (" + m_type + ")\n";
    for (auto* subElement : m_subElements) {
        result += (*subElement).toString(spaces + 2);
    }
    return result;
}

FileSystemBase* FileSystemBase::get(std::string name) const {
    for (auto* subElement : m_subElements) {
            if (subElement->getName() == name) {
                return subElement;
            } 
            else if (subElement->getType() == "DIR") {
                FileSystemBase* result = subElement->get(name);
                if (result != nullptr) {
                    return result;
                }
            }   
        } 
    return nullptr;
}
