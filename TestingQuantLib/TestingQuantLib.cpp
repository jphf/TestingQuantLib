// TestingQuantLib.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <ql/quantlib.hpp>
#include <iostream>

//int main()
//{
//    QuantLib::Calendar myCal = QuantLib::UnitedKingdom();
//    QuantLib::Date newYearsEve(31, QuantLib::Dec, 2008);
//
//    std::cout << "Name: " << myCal.name() << std::endl;
//    std::cout << "New Year is Holiday: " << myCal.isHoliday(newYearsEve) << std::endl;
//    std::cout << "New Year is Business Day: " << myCal.isBusinessDay(newYearsEve) << std::endl;
//
//    std::cout << "--------------- Date Counter --------------------" << std::endl;
//
//    QuantLib::Date date1(28, QuantLib::Dec, 2008);
//    QuantLib::Date date2(04, QuantLib::Jan, 2009);
//
//    std::cout << "First Date: " << date1 << std::endl;
//    std::cout << "Second Date: " << date2 << std::endl;
//    std::cout << "Business Days Betweeen: " << myCal.businessDaysBetween(date1, date2) << std::endl;
//    std::cout << "End of Month 1. Date: " << myCal.endOfMonth(date1) << std::endl;
//    std::cout << "End of Month 2. Date: " << myCal.endOfMonth(date2) << std::endl;
//
//    double tmp;
//    std::cin >> tmp;
//
//    return 0;
//}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
