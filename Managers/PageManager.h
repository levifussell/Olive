#ifndef PAGE_MANAGER
#define PAGE_MANAGER

#include "../Pages/Page.h"
#include "../DataStructures/LinkedList.h"

class PageManager
{
private:
    static LinkedList<Page*> pages;
    static int currentPageIndex;
public:
    static void initialise();
    static void unInitialise();
    static void addPage(Page* page);
    static Page* getCurrentPage();
    static void changePage(int index);
    static void loadCurrentPage();
    static void updateCurrentPage();
};

#endif
