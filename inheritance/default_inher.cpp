#include <iostream>

class Shape {
	 public:
		   // 定義一個虛擬函數
		   virtual void draw() {
			       std::cout << "Shape::draw" << std::endl;
				     }

		     // 定義一個非虛擬函數
		     void move() {
				     std::cout << "Shape::move" << std::endl;
					   }
};

class Circle : Shape {
	 public:
		   // 重寫父類別中的虛擬函數
		   void draw() override {
			       std::cout << "Circle::draw" << std::endl;
				     }

		     // 重寫父類別中的非虛擬函數
		     void move() {
				     std::cout << "Circle::move" << std::endl;
					   }
};

int main() {
	  Shape* s = new Circle();

	    // 呼叫虛擬函數，會呼叫子類別中的 draw 函數
	    s->draw();

		  // 呼叫非虛擬函數，會呼叫父類別中的 move 函數
		  s->move();

		    delete s;
			  return 0;
}
