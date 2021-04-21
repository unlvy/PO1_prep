#pragma once

#include <string>
#include <vector>
#include <iostream>

class FileSystemBase {

    friend std::ostream& operator<< (std::ostream& os, const FileSystemBase& f);

protected:
    std::string m_name;
    std::string m_type;
    std::vector<FileSystemBase*> m_subElements;

public:
    explicit FileSystemBase(std::string name, std::string type = "");
    virtual ~FileSystemBase();
    virtual std::string getName() const final;
    virtual std::string getType() const final;
    virtual void operator+= (FileSystemBase* subElement) final;
    virtual std::string toString(int spaces = 0) const final;
    virtual FileSystemBase* get(std::string name) const final;
};
