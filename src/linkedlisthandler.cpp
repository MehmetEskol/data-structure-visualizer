#include "linkedlisthandler.hpp"
#include "linkedlistitem.hpp"
#include "lineitem.hpp"

#include "linked_list.h"

#include <QPointer>
#include <QGraphicsScene>

class LinkedListHandler::Impl
{

public:

    LinkedList list;

    qreal lastItemHorizontalPosition {10.0};
    qreal lastItemVerticalPosition {10.0};
};

/**
 *
 */
LinkedListHandler::LinkedListHandler() : impl(std::make_unique<Impl>())
{
}

/**
 *
 */
LinkedListHandler::~LinkedListHandler() = default;

/**
 *
 */
void LinkedListHandler::createLinkedList(const int& data) &
{
    impl->list = createLL(data);
}

/**
 *
 */
void LinkedListHandler::insertAtTheEndLinkedList(const int& data) &
{
    insertAtTheEndLL(
        &impl->list,
        data
    );
}

/**
 *
 */
void LinkedListHandler::insertAtTheBeginningLinkedList(const int& data) &
{
    insertAtTheBeginningLL(
        &impl->list,
        data
    );
}

/**
 *
 */
void LinkedListHandler::dropAtIndexLinkedList(const int& index) &
{
    dropAtLL(
        &impl->list,
        index
    );
}

/**
 *
 */
void LinkedListHandler::insertAfterLinkedList(
    const int& index,
    const int& data
) &
{
    insertAfterLL(
        &impl->list,
        index,
        data
    );
}

/**
 *
 */
const unsigned int LinkedListHandler::getLinkedListLastIndex() const &
{
    return sizeLL(&impl->list) - 1;
}

/**
 *
 */
void LinkedListHandler::selectItem(
    const QGraphicsScene* scene,
    const int& index
) &
{
    auto allItems = scene->items(Qt::AscendingOrder);
    const auto length = allItems.size();

    constexpr int UNSELECTED_COLOR_RED {0};
    constexpr int UNSELECTED_COLOR_GREEN {0};
    constexpr int UNSELECTED_COLOR_BLUE {0};
    constexpr int UNSELECTED_COLOR_ALPHA {255};
    const auto unselectedColor = QColor(
        UNSELECTED_COLOR_RED,
        UNSELECTED_COLOR_GREEN,
        UNSELECTED_COLOR_BLUE,
        UNSELECTED_COLOR_ALPHA
    );

    constexpr int SELECTED_COLOR_RED {255};
    constexpr int SELECTED_COLOR_GREEN {0};
    constexpr int SELECTED_COLOR_BLUE {0};
    constexpr int SELECTED_COLOR_ALPHA {255};
    const auto selectedColor = QColor(
        SELECTED_COLOR_RED,
        SELECTED_COLOR_GREEN,
        SELECTED_COLOR_BLUE,
        SELECTED_COLOR_ALPHA
    );

    constexpr int BROWSED_COLOR_RED {0};
    constexpr int BROWSED_COLOR_GREEN {0};
    constexpr int BROWSED_COLOR_BLUE {255};
    constexpr int BROWSED_COLOR_ALPHA {255};
    const auto browsedColor = QColor(
        BROWSED_COLOR_RED,
        BROWSED_COLOR_GREEN,
        BROWSED_COLOR_BLUE,
        BROWSED_COLOR_ALPHA
    );

    constexpr int LINKED_LIST_NODES_STEPS {2};
    const auto linkedListNodeIndex = index * LINKED_LIST_NODES_STEPS;

    /* we want to iterate to each linked list node to another,
       each one is separated by a step; handle this is easier
       with a for loop rather than an iterator */
    for (
        auto i = 0;
        i < length;
        i += LINKED_LIST_NODES_STEPS
    ) {
        /* undefined behaviour if at(i) does not contain a pointer to a LinkedListItem*;
           in case of a linked list, this situation should not happen */
        auto currentItem = static_cast<LinkedListItem*>(allItems.at(i));

        QColor color = unselectedColor;

        if (i < linkedListNodeIndex)
        {
            color = browsedColor;
        }
        else if (i == linkedListNodeIndex)
        {
            color = selectedColor;
        }

        currentItem->setDefaultTextColor(color);
    }
}

/**
 *
 */
const unsigned int LinkedListHandler::getSize() const &
{
    return sizeLL(&impl->list);
}

/**
 *
 */
const unsigned int LinkedListHandler::getData(const unsigned short& index) const &
{
    return atLL(
        &impl->list,
        index
    );
}
