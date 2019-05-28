/*
 * incbyten.h
 * @author Dan Woolsey
 *
 * Header file for IncByTen example
 */

#ifndef __INCBYTEN__
#define __INCBYTEN__

class IncByTen
{
private:
    int value;
public:
    IncByTen(int _value);
    IncByTen& operator++(); // prefix inc operator (++i)
    IncByTen operator++(int); // postfix inc operator (i++)
    int get_value();
};

#endif
