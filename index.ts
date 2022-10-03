import LoadConfig from "./Services/LoadConfig";
import WatchTransactions from "./Services/WatchTransactions";
import Web3Factory from "./Services/Web3Factory";
import Web3Helper from "./Services/Web3Helper";

new LoadConfig();

(async () => {
    const web3 = Web3Factory.make();
    const web3Helper = new Web3Helper(web3);
    await web3Helper.init();

    new WatchTransactions(web3, web3Helper);
    // new ProfitLossManager(web3Helper);
})();
