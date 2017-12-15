#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node
{
	Node* parentNode;
	string label;
	vector<Node*> children; 
};

vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

Node* findInNodes(const string s, vector<Node*> nodes) {
	for (int i=0; i < nodes.size(); i++) {
		if (nodes[i]->label == s)
			return nodes[i];
	}
	return nullptr;
}

int main() {
	vector<Node*> nodes;
    ifstream inFile;
    string input;
    inFile.open("input.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    while(!inFile.eof()) // To get you all the lines.
    {
        getline(inFile,input);
        vector<string> values = split(input, ' ');
    	Node* node = findInNodes(values[0], nodes);
    	// if node doesn't exist create one
		if (!node) {
			printf("didnt find\n");
			Node* new_node = new Node;
			new_node->label = values[0];
			nodes.push_back(new_node);
			node = new_node;
		}
		printf("node processing %s\n", node->label.c_str());
    	if (values.size() > 2) {
    		vector<string> children_values = split(values[3], ',');
    		for (int i=0; i < children_values.size(); i++) {
		    	Node* child = findInNodes(children_values[i], nodes);
				if (!child) {
					printf("child doesnt exist %s\n", children_values[i].c_str());
					Node* new_node = new Node;
					// assign a label
					new_node->label = children_values[i];
					// assign a parent
					new_node->parentNode = node;
					// add it to greater node list
					nodes.push_back(new_node);
					// add it to parent node's children list
					node->children.push_back(new_node);
				} else {
					printf("child existed %s %s\n", child->label.c_str(), node->label.c_str());
					// assign a parent
					child->parentNode = node;
					// add it to parent node's children list
					node->children.push_back(child);					
				}

    		}
    	}
    	cout << endl << endl;
    }
    inFile.close();
	for (int i=0; i < nodes.size(); i++) {
		cout << nodes[i]->label << " " << nodes[i]->parentNode << endl;
		cout << "				" << nodes[i]->parentNode->label << endl;
		if (!nodes[i]->parentNode) {
			cout << "Answer: " << nodes[i]->label << endl;
		}
	}
    return 0;
}
