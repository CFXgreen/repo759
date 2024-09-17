#!/usr/bin/env zsh
#SBATCH -p instruction
#SBATCH --job-name=FirstSlurm
#SBATCH -o FirstSlurm-%j.out -e FirstSlurm-%j.err
#SBATCH --time=0-00:01:00
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=81
#SBATCH --cpus-per-task=1

cd $SLURM_SUBMIT_DIR

hostname