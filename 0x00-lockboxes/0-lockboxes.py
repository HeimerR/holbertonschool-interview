#!/usr/bin/python3
""" Lockboxes """


def updateboxes(boxes, boxes_state, keys):
    """ updates the state of boxes """
    last_keys = []
    for i in range(len(keys)):
        boxes_state[keys[i]] = "open"
        last_keys += boxes[keys[i]]
    return last_keys


def canUnlockAll(boxes):
    """  a method that determines if all the boxes can be opened """
    keys = [0]
    boxes_state = ["close" for i in boxes]
    while(True):
        prev_boxes_state = [row[:] for row in boxes_state]
        keys = updateboxes(boxes, boxes_state, keys)
        if prev_boxes_state == boxes_state:
            return False
        if (len(set(boxes_state)) == 1):
            return True
