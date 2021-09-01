#include "new_element_button.h"

NewElementButton::NewElementButton(Element *element, QString name, QWidget *parent) :
    QPushButton(parent),
    _element(element)
{
    this->setText(name);
    this->setFixedSize( 20 + name.size() * 10, 50 );
    connect(this, SIGNAL(clicked()), this, SLOT(addElement()));
}

NewElementButton::~NewElementButton()
{
}

void NewElementButton::addElement()
{
    emit click(_element->copy());
}

