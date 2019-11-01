
bool PartitionHelp(int *nums, int index, int sum, int** res)
{
    if (sum == 0)
        return true;
    if (sum < 0 || index < 0)
        return false;
	if(res[index][sum] != -1)
		return res[index][sum] == 1;
	
    res[index][sum] = PartitionHelp(nums, index - 1, sum, res) || PartitionHelp(nums, index - 1, sum - nums[index], res) ? 1 : 0;
	return res[index][sum] == 1;
}

bool canPartition(int* nums, int numsSize){
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    if ((sum % 2) != 0) {
        return false;
    }
    int memo[numsSize][sum/2];
	memset(memo, -1, sizeof(memo));
    // int** res = (int**)malloc(sizeof(int*) * numsSize);
    // for (int i = 0; i < numsSize; i++){
        // int* res = (int*)malloc(sizeof(int) * (sum/2));
    // }
    // for (int = 0;i < numsSize; i++) {
		// for (int j = 0; j < (sum / 2); j++) {
			// res[i][j] = -1;
		// }
	// }
    return PartitionHelp(nums, numsSize - 1, sum / 2, memo);
}