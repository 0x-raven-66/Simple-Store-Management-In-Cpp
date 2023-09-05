#include "product.h"
#include <iostream>
int main()
{
    products my_product;
    string role ;
    while(true)
    {
        cout<<"\t=>log in<="<<endl;
        cout<<"Enter Role:";
        cin>>role;
        if (role == "admin")
        {
                cout<<"welcome, "<<role<<endl;
            cout<<"You Can as admin do the next:"<<endl;
                while(true)
                {
                    char choise;
                    cout<<"(1)Add Products    (2)Show Products    (3)Delete Products    (Q)Log out"<<endl;
                    cout<<"choose:";
                    cin>>choise;
                    if(choise == 'Q')
                    {
                        cout<<"log out.\n"<<endl;
                        break;
                    }
                    else if (choise == '1')
                    {
                        string name;
                        int quantity;
                        double price;
                        cout<<"Add the name [space] quantity [space] price or Q to exit\n";
                        while(true)
                        {
                            cout<<"product details:";
                            cin>>name;
                            if (name == "Q"  )
                                break;
                            else
                            {
                                cin>>quantity;
                                cin>>price;
                                price=double(price);
                                my_product.add_product(name,quantity,price);
                                cout<<"------------------"<<endl;
                            }
                        }
                    }
                    else if (choise == '2')
                    {
                        my_product.show_product();
                        cout<<endl;
                    }
                    else if (choise == '3')
                    {
                        string name;
                        cout<<"Add the name or Q to exit"<<endl;
                        while(true)
                        {
                            cout<<"product name:";
                            cin>>name;
                            if (name == "Q" )
                                break;
                            else
                            {
                                my_product.delete_product(name);
                            }
                        }
                    }
                }
        }
        else if(role == "Q")
        {
            break;
        }
        else if (role == "cashier") {
            while (true)
            {
                cout<<"only can (1)sell    (2)show    (Q)log out \nchoose:";
                char cash;
                cin>>cash;

                string name;
                int number;
                if(cash=='2')
                {
                    my_product.show_product();
                }
                else if(cash=='1')
                {
                    cout << "Enter product name [space] quantity or Q to exit"<<endl;
                    double total_price=0, total = 0;
                    while (true)
                    {
                        cout << "product:";
                        cin >> name;
                        if (name == "Q")
                        {
                            break;
                        }
                        else
                        {
                            cin >> number;
                            total_price = my_product.sell_product(number, name);
                            cout<<"------------------"<<endl;
                            total += total_price;
                        }
                    }
                    cout << "Total Purchase = " << total<<"$"<<endl;
                }
                else
                    break;
            }
        }
    }
    }
