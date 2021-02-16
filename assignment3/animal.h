#ifndef ANIMAL_H
#define ANIMAL_H

class animal{
  private:
    
  protected:
    int age;
    int cost;
    bool sickness;
  public:
    int get_age() const;
    void add_age();
    void set_age(int);
    void sick();
    bool get_sick();
    int get_cost();
    void not_sick();
};

#endif
