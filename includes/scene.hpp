#ifndef SCENE_H_
#define SCENE_H_

#include <QGraphicsScene>

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:

    /**
     * @brief scene constructor
     */
    Scene();

public slots:

    /**
     * @brief called from the linked list menu creation action;
     * it creates a new linked list node on the scene
     *
     * @param data the data to insert into the first node
     */
    void createLinkedList(const int& data);
};

#endif
