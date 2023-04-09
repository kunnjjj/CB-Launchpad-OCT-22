#include <iostream>
using namespace std;

void repeatScenario()
{
    int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    int n, m;
    cin >> n >> m;
    int totalRick = 0;
    for (int i = 1; i <= n; i = i + 1)
    {
        int ri;
        cin >> ri;
        int indivisualRidesKeHisabSe = ri * c1;
        int isRickKoUnlimitedRidesKeLiyeLiya = c2;
        totalRick += min(isRickKoUnlimitedRidesKeLiyeLiya, indivisualRidesKeHisabSe);
    }

    totalRick = min(totalRick, c3);

    int totalCab = 0;
    for (int i = 1; i <= m; i = i + 1)
    {
        int ci;
        cin >> ci;
        int indivisualRidesKeHisabSe = ci * c1;
        int isCabKoUnlimitedRidesKeLiyeLiya = c2;
        totalCab += min(isCabKoUnlimitedRidesKeLiyeLiya, indivisualRidesKeHisabSe);
    }

    totalCab = min(totalCab, c3);

    int finalCost=min(totalCab + totalRick, c4);
    cout<<finalCost<<endl;
    
}
int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i = i + 1)
    {
        repeatScenario();
    }

    return 0;
}