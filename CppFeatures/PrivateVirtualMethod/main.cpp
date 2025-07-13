#include <iostream>
#include <memory>

class Base
{
  private:
    virtual void secret() const
    {
        std::cout << "Base::secret()\n";
    }

  public:
    virtual ~Base() = default;

	//Non-Virtual Interface (NVI) idiom
    void callSecret() const    // public interface to call the private virtual
    {
        secret();
    }
	
};

class Derived : public Base
{
  private:
    void secret() const override
    {
        std::cout << "Derived::secret()\n";
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

	//using new delete
    Base* obj = new Derived();
    obj->callSecret();  // calls Derived::secret() via Base::callSecret()
    delete obj;
    
	//using smart pointer
    std::unique_ptr<Base> obj2 = std::make_unique<Derived>();
    obj->callSecret();  // calls Derived::secret() via Base::callSecret()

	auto derObj = std::make_unique<Derived>();
	//derObj->secret(); //Error: 'secret' is a private member of 'Derived'
}
