class Solution:
  def largestIsland(self, grid: List[List[int]]) -> int:
    island_size = {}
    island_id = 2

    for current_row in range(len(grid)):
        for current_column in range(len(grid[0])):
            if(grid[current_row][current_column] == 1):
                island_size[island_id] = self.explore_island(
                    grid, island_id, current_row, current_column
                )
                island_id += 1;
    
    if not island_size:
       return 1
    
    if len(island_size) == 1:
       island_id -= 1
      return(
         island_size[island_id]
         if island_size[island_id] = len(grid) * len(grid[0])
         else island_size[island_id] + 1
      )

    max_island_size = 1
    