/*
File: MILESTONE 6

Name: SINA MONAJEMI
Email: smonajemi@myseneca.ca
Student Number: 021-324-124

Date: April 12, 2020 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
//#include <stdio.h> // debugging purposes 
using namespace std;
#include "Menu.h"

namespace sdds 
{

    MenuItem::MenuItem() {}

    MenuItem::MenuItem(const char* Mitem) 
    {
        setItem(Mitem);
    }


    MenuItem::~MenuItem() { clearMemory(); }


    std::ostream& MenuItem::display(std::ostream& os ) const
    {
        if (!isEmpty()) { os << m_menuitem << endl; }
        return os;
    }

    void MenuItem::setEmpty() 
    {
        m_menuitem = nullptr;
    }

    void MenuItem::setItem(const char* Mitem)
    {
        clearMemory();
        m_menuitem = new char[strlen(Mitem) + 1];
        strcpy(m_menuitem, Mitem);
    }
       
    void MenuItem::clearMemory()
    {
        delete[] m_menuitem;
        setEmpty();
    }

    bool MenuItem::isEmpty() const 
    {
        return m_menuitem == nullptr;
    }

    std::ostream& operator<<(std::ostream& os, const MenuItem& x) 
    {
        x.display(os);
        return os;
    }

    /********************************************************************************************************************************************* ENDING MENU ITEM MODULE *********************************************************************************************************************************************/
                                                                                        /********************************************************************************************************************************************** */
    void Menu::setTitle(const char* src) 
    {
        clearMemory();
        if (src != nullptr && src[0] != '\0') 
        {
            int size = (strlen(src) + 1);
            m_menu_title = new char[size];
            strcpy(m_menu_title, src);
        }
    }

    void Menu::set(const Menu& src)
    {
        int i;
        setTitle(src.m_menu_title);
        m_menu_num = src.m_menu_num;
        m_ind = src.m_ind;
        for (i = 0; i < m_menu_num; i++)
        {
            m_item[i] = new MenuItem(src.m_item[i]->m_menuitem);
        }
    }

    Menu::Menu() {}

    Menu::Menu(const char* src, int ind)
    {
        m_ind = ind;
        setTitle(src);
    }

    Menu::Menu(const Menu& src) 
    {
        set(src);      
    }

    Menu::~Menu() 
    {     
        clearMemory();
    }

    Menu& Menu::operator=(const Menu& src) 
    {
        if (this != &src) {
            clearMemory();
            if (!src.isEmpty()) { set(src); }
        }
        return *this;
    }

    Menu& Menu::operator<<(const char* src)
    {
        add(src);
        return *this;
    }

    Menu::operator int() const { return run(); }

    Menu::operator bool() const  { return !isEmpty(); }

    bool Menu::isEmpty() const
    {
        return (m_menu_title == nullptr);
    }

    void Menu::clearMemory() 
    {
        delete[] m_menu_title;
        m_menu_title = nullptr;
        for (int i = 0; i < m_menu_num; i++) 
        {
            delete m_item[i]; 
            m_item[i] = nullptr;
        }
        m_menu_num = 0;
    
    }

    void Menu::indentation(std::ostream& os, int x) const 
    {
        for (int i = 0; i < x * 4 ; i++) { os << " "; }
    }

    void Menu::add(const char* src) 
    {       
        if (src == nullptr) 
        {
            clearMemory();
        }
        if (src != nullptr)
        {
           m_item[m_menu_num++] = new MenuItem(src);
        }
    }

    int Menu::run() const
    {
        display();
        int input;

        while (m_menu_num > 0 && (!isEmpty()))
        {
            for (int i = 0;; i++) 
            {
                while (!(cin >> input))
                {
                    cout << "Invalid Integer, try again: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                if (input >= 1 && input <= m_menu_num)
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    return input;
                }
                else 
                {
                    cout << "Invalid selection, try again: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            }
        }

        return 0;
    }
    std::ostream& Menu::display(std::ostream& os) const
    {
        if (isEmpty())
        {
            os << "Invalid Menu!" << endl;
        }
        else
            if (m_menu_title != nullptr && m_item[0] == nullptr)
            {
                indentation(os, 2);
                os << m_menu_title << endl;
                os << "No Items to display!" << endl;
            }
            else if (m_menu_title != nullptr)
            {
                indentation(os, m_ind);
                os << m_menu_title << endl;

                for (int i = 0; i < m_menu_num; i++)
                {
                    indentation(os, m_ind);
                    os << (i + 1) << "-" << string(1, ' ');
                    m_item[i]->display(os);
                }
                indentation(os, m_ind);
                os << ">" << string(1, ' ');
            }
        return os;
    }



// END!
} // namespace sdds
