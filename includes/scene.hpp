#ifndef SCENE_H_
#define SCENE_H_

#include <QGraphicsScene>

#include <memory>

struct LinkedList;

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:

    /**
     * @brief scene constructor
     */
    Scene();

    /**
     * @brief default destructor
     */
    ~Scene();

    /**
     * @brief getter of the linked list structure
     *
     * @return LinkedList&
     */
    LinkedList& getLinkedList() const & noexcept;

    /**
     * @brief called from the linked list menu creation action;
     * it creates a new linked list node on the scene
     *
     * @param data the data to insert into the first node
     *
     * not const as adding an item to the scene modifies it
     */
    void createLinkedList(const int& data) &;

    /**
     * @brief called from the linked list menu end insertion action;
     * it creates a new linked list node to the end of the existing list
     *
     * @param data the data to insert into the first node
     *
     * not const as adding an item to the scene modifies it
     */
    void insertAtTheEndLinkedList(const int& data) &;

private:

    /**
     * @brief called everytime an item is added to the scene;
     * use the current position as the item position
     *
     * @param item the item with its position to be set
     */
    void applyCurrentItemPosition(QGraphicsTextItem* item) const &;

    /**
     * @brief called everytime an item is added to the scene;
     * increases the position of the currently inserted item
     */
    void increaseItemPositions() const & noexcept;

    class Impl;
    const std::unique_ptr<Impl> impl;
};

#endif
