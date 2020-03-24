/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** Object
*/

#include "Object.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

Object::Object(std::string name)
{
    _name = name;
}

Object &Object::operator=(const Object &obj)
{
    this->_name = obj._name;
    this->_taken = obj._taken;
    this->_type = obj._type;
    return *this;
}

Object **MyUnitTests()
{
    Object **obj = new Object*[2];
    obj[0]  = new LittlePony("happy pony");
    obj[1] = new Teddy("cuddles");
    return obj;
}

Object *MyUnitTests(Object **list)
{
    if (!(list[0]->getType() & TEDDY) ||
    !(list[1]->getType() & BOX) ||
    !(list[2]->getType() & G_PAPER)) {
        std::cout << "Type error on the list" << std::endl;
        return NULL;
    }
    list[1]->ret_buff_wrap()->wrapMeThat(*list[0]);
    list[2]->ret_buff_wrap()->wrapMeThat(*list[1]);
    return list[2];
}

std::string Object::type_to_str()
{
    int mod = 0;
    std::string res = "";
    int buf_type[6] = {TOY, PONNY, TEDDY, WRAP, BOX, G_PAPER};
    char buf_str[6][11] = {"Toy", "Ponny", "Tedddy", "Wrap", "Box", "Gift_paper"};

    for (int i = 0; i < 6; i++)
        if (_type & buf_type[i]) {
            if (mod)
                res += " and ";
            mod++;
            res += buf_str[i];
        }
    return res;
}

int main() // ! 1 MY_UNIT_TEST
{
    Object **test1 = MyUnitTests();
    std::cout << "Name : "<< test1[0]->getName()<< "; type : " << test1[0]->type_to_str() << "\n";
    std::cout << "Name : " << test1[1]->getName()<< "; type : " << test1[1]->type_to_str() << std::endl;
    return 0;
}
/*
int main()
{
    std::cout << "\e[92;1m*******************TEST*EN*DUR********************\e[0m" << std::endl;
    Teddy ted = Teddy("Tedy0");
    Box box = Box();
    GiftPaper g_paper = GiftPaper();

    std::cout <<g_paper.isGift() << std::endl;
    box.wrapMeThat(ted);
    g_paper.wrapMeThat(box);
    std::cout << g_paper.isGift() << std::endl;
    std::cout << box.openMe()->getName() << std::endl;
    std::cout << box.openMe() << std::endl;

    std::cout << "\e[92;1m****************My*Unit*Tests*2*******************\e[0m" << std::endl;

    Object **obj = new Object*[3];
    obj[0] = new Teddy("Tedy1");
    obj[1] = new Box();
    obj[2] = new GiftPaper();
    std::cout << obj[2]->ret_buff_wrap()->isGift() << std::endl;
    Object *res = MyUnitTests(obj);
    std::cout <<obj[2]->ret_buff_wrap()->isGift() << std::endl;
    std::cout << obj[1]->ret_buff_wrap()->openMe()->getName() << std::endl;
    std::cout << obj[1]->ret_buff_wrap()->openMe() << std::endl;

}*/