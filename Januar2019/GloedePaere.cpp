#include "GloedePaere.h"

GloedePaere::GloedePaere(double forbrug, double lysstyrke, string filamenttype = "Wolfram")
    : Lyskilde(forbrug, lysstyrke), filamenttype_(filamenttype != "" ? filamenttype : "Wolfram")
{
}

void GloedePaere::setFilamenttype(string filamenttype)
{
    filamenttype_ = filamenttype;
}


string GloedePaere::getFilamenttype() const
{
    return filamenttype_;
}

bool GloedePaere::getDaempbar() const
{
    return true;
}

void GloedePaere::print() const
{
    cout << "Gloedeparere med filanment af: " << getFilamenttype() << endl;
    Lyskilde::print();
}
