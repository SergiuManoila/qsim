#include<iostream>
#include<complex>
#include<math.h>
#include<vector>

using namespace std;

class simulator
{

unsigned int possible_states; //2^(number of qubits we want)
vector<complex<double>> state_vector; //the state vector

vector<vector<complex<double>>> operand;
//the matrix we mutiply the state vector with, will be built from the various gates we want to apply

public: simulator(unsigned int qubit_nr)
{
    this->possible_states = 1 << qubit_nr;
    //calculate and store 2^qubit_nr not to do it each time
    state_vector.assign(this->possible_states, complex<double>(0.0, 0.0));
    //assign complex value 0,0 to all values in the state vector
    state_vector[0] = complex<double>(1.0, 0.0);
    //assign 1,0 to the [0,0,0,....,0] state

    this->operand.assign(possible_states, vector<complex<double>>(possible_states, {0.0, 0.0}));
    //initialise with 0,0 on all cells the matrix that will be the operand for our state
    for (unsigned int i = 0; i < possible_states; i++) this->operand[i][i] = {1.0, 0.0};
    //overwrite 1,0 to all cells on the main diagonal, transforming the operand matrix to be the identity matrix
};

public: void apply_operand()
{

auto clone_state = this->state_vector;

for(unsigned int i=0;i<this->possible_states;i++)
    {
    state_vector[i] = {0.0, 0.0};  // reset before summing
    for(unsigned int j=0;j<this->possible_states;j++)
        this->state_vector[i]+=this->operand[i][j]*clone_state[j];

    }
};

private: vector<vector<complex<double>>> tensor_product(vector<vector<complex<double>>> A,vector<vector<complex<double>>> B)
{
    
}

};


int main()
{
    cout<<"hello world";


}