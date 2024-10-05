#!/usr/bin/bash
#SBATCH -p instruction
#SBATCH --job-name=task1
#SBATCH -o task1-%j.out -e task1-%j.err
#SBATCH --time=0-00:04:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=10
#SBATCH --cpus-per-task=1
cd $SLURM_SUBMIT_DIR
# load the gcc for compiling C++ programs
module load gcc/13.2.0
# load the nvcc for compiling cuda programs
module load nvidia/cuda
# clone (replace the github link to yours)
git clone https://github.com/CFXgreen/repo759.git
cd repo759/HW02
g++ scan.cpp task1.cpp -Wall -O3 -std=c++17 -o task1

./task1 2048