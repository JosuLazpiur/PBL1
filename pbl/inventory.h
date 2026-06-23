// inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H

#include "initializer.h" // Include necessary headers

extern SDL_Point start_drag_position;
extern SDL_Rect dragged_item_rect;
extern SDL_Rect original_inventory_slot_rect;
extern int dragged_item_index;
extern int inventorySlotSize;
extern int inventorySpacing;
extern int inventoryX;
extern int inventoryY;
extern int using_item;
extern int large_inventory_open;
extern int currentItemSlot;
extern int currentItemIndex;

typedef struct InventorySlot_S {
    int itemIndex;
    int quantity;
    SDL_Texture* texture;
    int isSelected;
} InventorySlot;

typedef struct PlayerInventory_S {
    InventorySlot slots[15];
} PlayerInventory;


extern PlayerInventory playerInventory;


typedef struct Item_S {
    const char* name;
    int usable;
    const char* imagePath;
    SDL_Texture* texture;
}Item;

extern Item gameItems[];


void render_inventory();
void handle_drag_and_drop(SDL_Event* event);
void use_inventory();
void use_item(int itemindex, int slot);
void add_item(int index, int quantity);
void remove_item(int index, int quantity);
int has_item(int index);

#endif // INVENTORY_H;
