#include "PageManager.h"

LinkedList<Page*> PageManager::pages;
int PageManager::currentPageIndex;

void PageManager::initialise()
{
    currentPageIndex = -1;
}

void PageManager::unInitialise()
{
    pages.clear();
}

void PageManager::addPage(Page* page)
{
    pages.push_back(page);
}

Page* PageManager::getCurrentPage()
{
    if(currentPageIndex != -1)
        return pages.getAtIndex(currentPageIndex);
    else
        return 0;
}

void PageManager::changePage(int index)
{
    currentPageIndex = index;

    loadCurrentPage();
}

void PageManager::loadCurrentPage()
{
    if(currentPageIndex != -1)
    {
        Page* currPage = pages.getAtIndex(currentPageIndex);

        if(currPage && !currPage->isInitialised())
            currPage->initialise();
    }
}

void PageManager::updateCurrentPage()
{
    if(currentPageIndex != -1)
    {
        Page* currPage = pages.getAtIndex(currentPageIndex);

        if(currPage)
        {
            currPage->update();
        }
    }
}
