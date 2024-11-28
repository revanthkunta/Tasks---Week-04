#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Structure representing a UI control element
struct ControlElement {
    int identifier;
    string elementType, visibilityState;
};

int main() {
    vector<ControlElement> controlList;

    // Adding control elements to the vector
    controlList.push_back({ 1, "slider", "visible" });
    controlList.push_back({ 2, "button", "invisible" });
    controlList.push_back({ 3, "button", "visible" });
    controlList.push_back({ 4, "slider", "disabled" });
    controlList.push_back({ 5, "button", "visible" });
    controlList.push_back({ 6, "slider", "invisible" });
    controlList.push_back({ 7, "button", "visible" });
    controlList.push_back({ 8, "slider", "visible" });
    controlList.push_back({ 9, "button", "visible" });
    controlList.push_back({ 10, "slider", "disabled" });

    // Displaying the control elements
    for (const auto& control : controlList) {
        cout << "Identifier: " << control.identifier << endl;
        cout << "Element Type: " << control.elementType << endl;
        cout << "Visibility State: " << control.visibilityState << endl;
    }

    // Searching for a control with a specific ID
    ControlElement searchElement = { 2, "", "" };
    auto findResult = find_if(controlList.begin(), controlList.end(), [&](const ControlElement& element) {
        return element.identifier == searchElement.identifier;
        });

    if (findResult != controlList.end()) {
        cout << "Control found: ID " << findResult->identifier
            << ", Type: " << findResult->elementType
            << ", State: " << findResult->visibilityState << endl;
    }
    else {
        cout << "Control with ID " << searchElement.identifier << " not found." << endl;
    }

    cout << endl;

    // Finding consecutive controls with the same visibility state
    auto consecutive = adjacent_find(controlList.begin(), controlList.end(), [](const ControlElement& a, const ControlElement& b) {
        return a.visibilityState == b.visibilityState;
        });

    if (consecutive != controlList.end()) {
        cout << "Consecutive controls with the same state found at IDs: "
            << consecutive->identifier << " and " << (consecutive + 1)->identifier << endl;
    }
    else {
        cout << "No consecutive controls with the same state found." << endl;
    }

    // Counting the number of "disabled" controls
    int disabledCount = count_if(controlList.begin(), controlList.end(), [](const ControlElement& element) {
        return element.visibilityState == "disabled";
        });

    cout << "Number of disabled controls: " << disabledCount << endl;

    // Checking if all elements in a subrange are equal
    bool isEqual = equal(controlList.begin(), controlList.begin() + 1, controlList.end(), [](const ControlElement& a, const ControlElement& b) {
        return a.visibilityState == b.visibilityState && a.elementType == b.elementType;
        });

    if (isEqual) {
        cout << "All subranges are equal." << endl;
    }
    else {
        cout << "Subranges are not equal." << endl;
    }

    return 0;
}
