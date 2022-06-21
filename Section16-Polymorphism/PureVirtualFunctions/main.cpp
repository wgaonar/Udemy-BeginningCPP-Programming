// Section 16
// Pure virtual functions and abstract base classes
#include <iostream>
#include <vector>

class Shape // Abstract Base class
{			
private:
  // attributes common to all shapes
public:
  virtual void draw() = 0;	    // pure virtual function
  virtual void rotate() = 0;    // pure virtual function
  virtual ~Shape() {};
};

class Open_Shape: public Shape  // Abstract class
{    
public:
  virtual ~Open_Shape() {};
};

class Closed_Shape : public Shape // Abstract class
{  
public:
  virtual ~Closed_Shape() {};
};

class Line: public Open_Shape // Concrete class
{     
public:
    virtual void draw() override 
    {
      std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override 
    {
      std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line() {};
};

class Circle: public Closed_Shape // Concrete class
{     
public:
  virtual void draw() override 
  {
    std::cout << "Drawing a circle" << std::endl;
  }
  virtual void rotate() override 
  {
    std::cout << "Rotating a circle" << std::endl;
  }
  virtual ~Circle() {};
};

class Square: public Closed_Shape // Concrete class
{     
public:
  virtual void draw() override 
  {
    std::cout << "Drawing a square" << std::endl;
  }
  virtual void rotate() override 
  {
    std::cout << "Rotating a square" << std::endl;
  }
    virtual ~Square() {};
};


void screen_refresh(const std::vector<Shape *> &shapes) 
{
  std::cout << "Refreshing" << std::endl;
  for (const auto p: shapes) 
    p->draw();
}

int main() 
{
  // Shape s;    // Error, Shape is the abstract base class
  // Shape *p = new Shape(); // Error, Shape is the abstract base class

  // Closed_Shape s; // Error, Closed_Shape is the abstract base class
  // Shape *p = new Closed_Shape(); // Error, Close_Shape is the abstract base class

  std::cout << "\n === Static Object Circle ==== " << std::endl;
  Circle c;
  c.draw();
  c.rotate();

  std::cout << "\n === Polymorphism Circle ==== " << std::endl;
  Shape *ptr = new Circle();
  ptr->draw();
  ptr->rotate();

  std::cout << "\n === Polymorphism Objects ==== " << std::endl;
  Shape *s1 = new Circle();
  Shape *s2 = new Line();
  Shape *s3 = new Square();
    
  std::vector<Shape *> shapes {s1,s2,s3};
  for (const auto p: shapes) 
    p->draw();
        
  std::cout << "\n === Polymorphism with a Function ==== " << std::endl;
  screen_refresh(shapes);
    
  std::cout << "\n === Clean up ==== " << std::endl;
  delete s1;
  delete s2;
  delete s3;
  
  return 0;
}

