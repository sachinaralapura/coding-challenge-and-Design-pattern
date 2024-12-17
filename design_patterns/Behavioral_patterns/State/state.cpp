#include "state.h"

int main()
{

    VendingMachineContext *context = new VendingMachineContext();
    context->setState(new ReadyState());
    context->request();
    context->setState(new ProductSelectedState());
    context->request();
    context->setState(new PaymentPendingState());
    context->request();
    context->setState(new OutOfStockState());
    context->request();
    return 0;
}
