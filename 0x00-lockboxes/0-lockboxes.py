#!/usr/bin/python3
""" Lockboxes """


def updateboxes(boxes, boxes_state, keys):
    """ updates the state of boxes """
    last_keys = []
    for i in range(len(keys)):
        boxes_state[keys[i]] = True
        last_keys += boxes[keys[i]]
    return last_keys


def canUnlockAll(boxes):
    """  a method that determines if all the boxes can be opened """
    keys = [0]
    boxes_state = [False for i in boxes]
    for i in range(len(boxes)):
        keys = updateboxes(boxes, boxes_state, keys)
    return all(boxes_state)
