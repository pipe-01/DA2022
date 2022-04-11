// Sort the jobs based on their deadlines.
// Iterate from the end and calculate the available slots between every two consecutive deadlines. Include the profit, deadline, and job ID of ith job in the max heap.
// While the slots are available and there are jobs left in the max heap, include the job ID with maximum profit and deadline in the result.
// Sort the result array based on their deadlines.

// Time complexity : O(nlog(n))
// Space complexity : O(n)

#include <iostream>

// Estafeta = volume máximo, peso máximo e custo/percentagem
// Encomenda = Volume, peso e recompensa    


//ordenar os pagamentos dos estafetas por ordem crescente
// escolher o primeiro
// ordem decrescente de profit
// ver se e viavel
// se nao for exclui solução
// se for adiciona e passa ao seguinte