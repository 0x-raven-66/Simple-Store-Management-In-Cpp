#include <iostream>
using namespace std;
class node
{
public:
    double price;
    int quantity;
    string name;
    node *next;
    node()
    {
        next = nullptr;
    }
};
class products
{
public:
    int length = 0;
    node *head;
    products()
    {
        head = nullptr;
    }
    bool find(string name);
    double get_price(string name);
    bool set_quantity(int number,string name);
    void add_product(string name,int quantity, double price);
    void delete_product(string name);
    void show_product();
    double sell_product(int number, string name);
};
bool products::find(string name)
{
    node *travel = head;
    while (travel->name != name && travel->next != nullptr)
    {
        travel = travel->next;
    }
    if (travel->name == name)
        return true;
    else
        return false;

}

void products::add_product(string name,int quantity, double price)
{
    node *new_product = new node();
    new_product->name = name;
    new_product->quantity=quantity;
    new_product->price = price;
    if (head == nullptr)
    {
        head = new_product;
    }
    else
    {
        new_product->next = head;
        head = new_product;
    }
    length++;
}
void products::delete_product(string name)
{
    if (head == nullptr)
    {
        cout << "The Storage Is Already Empty "<<endl;
    }
    else if (find(name) == false)
    {
        cout<<name<<" isn't in the storage"<<endl;
    }
    else if (find(name) == true)
    {
        if (head->name == name)
        {
            node * temp = head;
            head = temp->next;
            delete temp;
        }
        else
        {
            node *travel = head;
            while (travel->next->name != name)
            {
                travel = travel->next;
            }
            node *deleted = travel->next;
            travel->next = deleted->next;
            delete deleted;
        }
        length--;
        cout<<name<<" deleted."<<endl;
    }
}
void products::show_product()
{
    cout << length << " Products In The Storage.\n";
    cout << "Name\t--\tquantity\t--\tPrice\n";
    node *travel = head;
    while (travel != nullptr)
    {
        cout << travel->name <<"\t||\t"<< travel->quantity<< "\t\t||\t" << travel->price << "\n";
        travel = travel->next;
    }
}
double products::get_price(string name)
{
    node *travel = head;
    while (travel->name != name && travel->next != nullptr)
    {
        travel = travel->next;
    }
    if (travel->name == name)
        return travel->price;
    else
        return false;
}
bool products::set_quantity(int number,string name)
{
    node *travel = head;
    while (travel->name != name && travel->next != nullptr)
    {
        travel = travel->next;
    }
    if (travel->name == name)
    {
        if(number > travel->quantity)
            return false;
        else
        {
            travel->quantity -= number;
            return true;
        }

    }

    else
        return false;
}
double products::sell_product(int number, string name)
{
    if (get_price(name))
    {
        if(set_quantity(number,name))
        {
            double pr=0,total_pr=0;
            pr = get_price(name);
            total_pr = pr * number;
            cout << number << " " << name << " total: " << total_pr<<"$"<<endl;
            return total_pr;
        }
        else
            cout<<"Not Enough Quantity In Storage."<<endl;

    }
    else
        cout << "Not In The Storage."<<endl;
}