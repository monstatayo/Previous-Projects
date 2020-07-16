/*COP 3502C Final term Assignment 2
This program is written by: Gabriel Kim-Perez*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct tree_node{

    char * name;
    struct tree_node *left;
    struct tree_node *right;

  }tree_node;

  int max(int a, int b);
  tree_node* minVal(tree_node *root);
  int numnodes(tree_node* root);
  tree_node* newnode(char * c);
  tree_node* insert(tree_node *root, tree_node *element);
  tree_node* parent(tree_node *root, tree_node *node);
  tree_node* searchNode(tree_node * root, char * c);
  tree_node* delete(tree_node* root, char * c);
  int totalChar(tree_node * root);
  int isBal(tree_node * root);
  int getHeight (tree_node * root);
  int getLeftHeight(tree_node * root);
  int getRightHeight(tree_node * root);
  void preorder(tree_node *current_ptr, FILE* out);
  void inorder(tree_node *current_ptr, FILE* out);
  void postorder(tree_node *current_ptr, FILE* out);
  int isLeaf(tree_node * node);
  int hasOnlyLeftChild(tree_node * node);
  int hasOnlyRightChild(tree_node * node);

  int max(int a, int b){

    if(a >= b) return a;
    else return b;

    }
  tree_node* newnode(char * c){

    tree_node *temp;
    temp = (tree_node*) malloc(sizeof(tree_node));

    temp->name = c;
    temp->left = NULL;
    temp->right = NULL;

    return temp;

      }

  int numnodes(tree_node* root) {

    if (root == NULL) return 0;

       return 1 + numnodes(root->left) + numnodes(root->right);
    }

  tree_node* minVal(tree_node *root) {

      if (root->left == NULL)
       return root;

     else
        return minVal(root->left);
    }    

  tree_node* insert(tree_node *root, tree_node *element) {

    if (root == NULL){
      return element;
      }

    else {

    if (strcmp(element->name , root->name) > 0) {

      if (root->right != NULL)
        root->right = insert(root->right, element);

      else
        root->right = element;
    }

    else {

      if (root->left != NULL)
        root->left = insert(root->left, element);

      
      else
        root->left = element;
         }

    return root;

      }
    }
  

  tree_node* parent(tree_node *root, tree_node *node) {

   if (root == NULL || root == node)
    return NULL;

 
    if (root->left == node || root->right == node)
    return root;

   if (strcmp(node->name,root->name) < 0)
    return parent(root->left, node);

   else if (strcmp(node->name, root->name) > 0)
    return parent(root->right, node);

    return NULL; 

    }


  tree_node * searchNode(tree_node * root, char * c){
  
    if (root != NULL) {

  
     if (strcmp(c, root->name) == 0)
        return root;

  
     if (strcmp(c, root->name) < 0)
       return searchNode(root->left, c);

    
      else if (strcmp(c, root->name) > 0)
        return searchNode(root->right, c);

     }

      else return 0;
  
   }


  tree_node* delete(tree_node* root, char * c) {

        tree_node *delnode, *new_del_node, *save_node;
        tree_node *par;
        char * save_val;

       delnode = searchNode(root, c); 

        par = parent(root, delnode); 

         if (isLeaf(delnode)) {

           if (par == NULL) {

            free(root); 
                 return NULL;
            }

           if (strcmp(c, par->name) < 0) {

            free(par->left); 
            par->left = NULL;

            }

          else if (strcmp(c, par->name) > 0) {

            free(par->right); 
            par->right = NULL;

            }

           return root; 

         }

        
         if (hasOnlyLeftChild(delnode)) {

          
           if (par == NULL) {

              save_node = delnode->left;
              free(delnode); 
              return save_node; 

           }

          
            if (strcmp(c, par->name) < 0) {

             save_node = par->left; 
             par->left = par->left->left; 
             free(save_node); 
          }

          
            else if (strcmp(c, par->name) > 0) {
             save_node = par->right; 
             par->right = par->right->left; 
              free(save_node); 
           }

            return root; 
          }

        
          if (hasOnlyRightChild(delnode)) {

          
            if (par == NULL) {
              save_node = delnode->right;
              free(delnode);
              return save_node;
            }

          
           if (strcmp(c, par->name) < 0) {
             save_node = par->left;
             par->left = par->left->right;
             free(save_node);
            }

          
            else if (strcmp(c, par->name) > 0) {
             save_node = par->right;
             par->right = par->right->right;
             free(save_node);
            }
           return root;
         }

        
          new_del_node = minVal(delnode->right);
          save_val = new_del_node->name;

          delete(root, save_val);  

         delnode->name = save_val;

         return root;
    }


  int isBal(tree_node * root) {

      int left = getLeftHeight(root);
      int right = getRightHeight(root);

      if (abs(left - right) > 1){
        return 0;
      }
      else return 1;

    }



  int getHeight (tree_node * root){

    int left, right;

    if (root == NULL) return 0;

    left = getHeight(root->left);
    right = getHeight(root->right);

    return (max(left, right) + 1);


    }
  
  int getLeftHeight(tree_node * root){
    
    if (root == NULL) return -1;
    return (getHeight(root->left));
   }
  int getRightHeight(tree_node * root){
    if (root->right == NULL) return -1;
    return (getHeight(root->right));
    }

  int totalChar(tree_node * root){

        if (root != NULL)
          return strlen(root->name) + totalChar(root->left)+
                totalChar(root->right);
        else
         return 0;

   }


  void preorder(tree_node *current_ptr, FILE* out) {


    if (current_ptr != NULL) {
    
     fprintf(out,"%s ", current_ptr->name);
     preorder(current_ptr->left, out); 
     preorder(current_ptr->right, out); 
     }


    }


  void inorder(tree_node *current_ptr, FILE* out) {

   if (current_ptr != NULL) {
      inorder(current_ptr->left, out); 
      fprintf(out,"%s ", current_ptr->name); 
      inorder(current_ptr->right, out); 
     }
  
    }
    

  void postorder(tree_node *current_ptr, FILE* out) {

   if (current_ptr != NULL) {

      postorder(current_ptr->left, out); 
      postorder(current_ptr->right, out);
      fprintf(out,"%s ", current_ptr->name);  

     }

    }


  int isLeaf(tree_node * node) {

    return (node->left == NULL && node->right == NULL);

    }


  int hasOnlyLeftChild(tree_node * node) {

    return (node->left!= NULL && node->right == NULL);

    }


  int hasOnlyRightChild(tree_node * node) {

    return (node->left== NULL && node->right != NULL);

    }

  
  
  int main(void){

    tree_node * root = NULL;
    tree_node * element = NULL;
   
    FILE* in;
    FILE* out;
    

    in = fopen("in.txt", "r");
    out = fopen("out.txt", "w");


    int N,S,D;

    fscanf(in, "%d %d %d", &N, &S, &D);

    char * words [N];
    char * searchWords [S];
    char * deleteWords[D];
    
  
    for (int i = 0; i < N; i++)  {
      
      fscanf(in, "%s", &words[i]);

      element = (tree_node *)malloc(sizeof(tree_node));
      element = newnode(&words[i]);
      root = insert(root, element);
  
    }

  
    fprintf(out, "Pre Order: ");
    preorder(root, out);
    fprintf(out, "\nIn Order: ");
    inorder(root, out);    
    fprintf(out, "\nPost Order: ");
    postorder(root, out);

    fprintf(out, "\nTotal characters: %d", totalChar(root));

    fprintf(out, "\nHeight left = %d", getLeftHeight(root)-1);
    fprintf(out, ", height right = %d. ", getRightHeight(root)-1);
 


    if (isBal(root) == 0){

      fprintf(out, "The tree is imbalanced.");

    }

    else if (isBal(root) == 1) {
      
      fprintf(out, "The tree is balanced.");

    }
    
    fprintf(out, "\nSearch Phase:\n");

    for (int j = 0; j < S; j++){

       fscanf(in, "%s", &searchWords[j]);
       fprintf(out, "%s: ", &searchWords[j]);

        if (searchNode(root, &searchWords[j]) == 0){

             fprintf(out, "Not Found, ");

        }

        else 
            
             fprintf(out, "Found, ");
    
        
        }


    fprintf(out, "Delete Phase:\n");

    for (int k = 0; k < D; k++){

         fscanf(in, "%s", &deleteWords[k]);
         fprintf(out, "%s: deleted\n", &deleteWords[k]);
         root = delete(root, &deleteWords[k]);
           }
    
    fprintf(out, "In Order: ");
    inorder(root, out);
    fprintf(out, "\nTotal characters: %d", totalChar(root));

    fclose(out);
    fclose(in);
    free(root);
    free(element);
}