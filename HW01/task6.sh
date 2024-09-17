#!/usr/bin/env zsh
#SBATCH -p instruction
#SBATCH --job-name=task6
#SBATCH -o task6-%j.out -e task6-%j.err
#SBATCH --time=0-00:01:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=81
#SBATCH --cpus-per-task=1

cd $SLURM_SUBMIT_DIR

# load the gcc for compiling C++ programs
module load gcc/13.2.0
# load the nvcc for compiling cuda programs
module load nvidia/cuda
# clone (replace the github link to yours)
git clone https://github.com/CFXgreen/repo759.git
cd repo759/HW01
g++ task6.cpp -Wall -O3 -std=c++17 -o task6
./task6 6
