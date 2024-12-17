#include <iostream>

using namespace std;

class VendingMachineState
{
public:
    virtual void handleRequest() = 0;
};

class ProductSelectedState : public VendingMachineState
{
public:
    void handleRequest() override
    {
        cout << "Product selected state : Processing payment." << endl;
    }
};
class ReadyState : public VendingMachineState
{
public:
    void handleRequest() override
    {
        cout << "Ready state: Please select a product." << endl;
    }
};
class PaymentPendingState : public VendingMachineState
{
public:
    void handleRequest() override
    {
        cout << "Payment pending state: Dispensing product." << endl;
    }
};
class OutOfStockState : public VendingMachineState
{
public:
    void handleRequest() override
    {
        cout << "Out of stock state: Product unavailable. Please select another product." << endl;
    }
};

class VendingMachineContext
{
private:
    VendingMachineState *state;

public:
    VendingMachineContext() { state = 0; };
    VendingMachineContext(VendingMachineState *state) : state(state) {};
    void setState(VendingMachineState *state)
    {
        if (state != 0)
        {
            delete this->state;
            this->state = state;
        }
        else
            this->state = state;
    }
    void request()
    {
        this->state->handleRequest();
    }
};
