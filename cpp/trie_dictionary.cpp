#include <bits/stdc++.h>
#include <fstream>
using namespace std;

#define ALPHABET_SIZE (26)

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

unordered_map<string, string> m;
// trie node
struct Trie
{
    struct Trie *children[ALPHABET_SIZE];

    bool isWordEnd;
};

// Returns new trie node
struct Trie *getNode(void)
{
    struct Trie *pNode = new Trie;
    pNode->isWordEnd = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(struct Trie *root, const string key)
{
    struct Trie *pCrawl = root;

    for (int l = 0; l < key.length(); l++)
    {
        int index = CHAR_TO_INDEX(key[l]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isWordEnd = true;
}

// Returns true if key presents in trie, else false
bool search(struct Trie *root, const string key)
{
    int length = key.length();
    struct Trie *pCrawl = root;
    for (int level = 0; level < length; level++)
    {
        int index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isWordEnd);
}

// Returns 0 if current node has a child
// If all children are NULL, return 1.
bool isLastNode(struct Trie *root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return 0;
    return 1;
}

// Recursive function to print auto-suggestions for given node
void suggestionsRec(struct Trie *root, string currPre)
{
    // found a string in Trie with the given prefix
    if (root->isWordEnd)
    {
        cout << currPre << " = " << m[currPre];
        cout << endl;
    }

    // All children struct node pointers are NULL
    if (isLastNode(root))
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        {
            // append current character to currPrefix string
            currPre.push_back(97 + i);

            suggestionsRec(root->children[i], currPre);
            // remove last character
            currPre.pop_back();
        }
    }
}

// print suggestions for given query prefix.
int printWordsPrefix(Trie *root, const string query, int op)
{
    struct Trie *pCrawl = root;

    int level;
    int n = query.length();
    for (level = 0; level < n; level++)
    {
        int index = CHAR_TO_INDEX(query[level]);

        // no string in the Trie has this prefix
        if (!pCrawl->children[index])
            return 0;

        pCrawl = pCrawl->children[index];
    }

    // If prefix is present as a word.
    bool isWord = (pCrawl->isWordEnd == true);

    // If prefix is last node of tree (has no
    // children)
    bool isLast = isLastNode(pCrawl);

    if (isWord && op == 2)
    {
        cout << query << " = " << m[query] << endl;
        return 1;
    }

    if (!isWord && op == 2)
    {
        cout << "There is no such word in the dictionary" << endl;
        return -1;
    }
    // If prefix is present as a word, but
    // there is no subtree below the last
    // matching node.
    if (isWord && isLast)
    {
        cout << query << " = " << m[query] << endl;
        return -1;
    }

    // If there are are nodes below last
    // matching character.
    if (!isLast)
    {
        string prefix = query;
        suggestionsRec(pCrawl, prefix);
        return 1;
    }
    return 0;
}
int main()
{
    cout << "||||||----------Dictionary With Prefix----------||||||\n"
         << endl;

    char ch = 's';
    while (ch != 'q')
    {
        cout << "Press s to start the system and q to quit" << endl;
        cin >> ch;
        if (ch == 'q')
            return 0;
        if(ch!='s')
            continue;

        int op1, op2, op3;
        cout << "Operations to perform:" << endl;
        cout << "1. Get Complete dictionary" << endl
             << "2. Get meaning of entered word" << endl;
        cout << "3. Get word meanings with entered prefix" << endl
             << "4. Add word meanings\n"
             << endl;

        int op;
        cout << "Enter the option from above operations to perform: ";
        cin >> op;
        if (op == 1)
            cout << endl;

        if(op==4){
            ofstream myfile;
            myfile.open("dictionary.txt", ios_base::app);
            int m;
            cout<<"Enter number of word meanings you want to enter:";
            cin>>m;
            cout<<"Enter the word meaning in the given format: x-y"<<endl;
            cout<<"Put the word in place of x and meaning in place of y. Do not forget to add '-' in between without space."<<endl;
            cin.ignore();
            while(m--){
                string s;                
                getline(cin, s);
                s += "\n";
                myfile<<s;
            }
            myfile.close();
            continue;
        }
        struct Trie *root = getNode();
        string word, meaning;
        ifstream myfile;
        myfile.open("dictionary.txt");
        char output[100];
        if (myfile.is_open())
        {
            string tp;
            while (getline(myfile, tp))
            {
                int pos = tp.find("-");
                word = tp.substr(0, pos);

                meaning = tp.substr(pos + 1, tp.length());
                insert(root, word);
                if (op == 1)
                    cout << word << " : " << meaning << endl;
                m[word] = meaning;
            }
        }
        myfile.close();

        if (op == 2 || op == 3)
        {
            string check;
            if (op == 2)
                cout << "Enter the word: ";
            else if (op == 3)
                cout << "Enter the prefix: ";
            cin.ignore();
            getline(cin, check);

            cout << endl
                 << "Given below are resulted word meanings:" << endl;
            int comp = printWordsPrefix(root, check, op);
        }
    }

    return 0;
}
