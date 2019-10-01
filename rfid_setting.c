#include "driver/spi_slave.h"
#include "esp_spi_flash.h"

#include "proj_inc/rfid_setting.h"

//Called after a transaction is queued and ready for pickup by master.
void my_post_setup_cb(spi_slave_transaction_t *trans)
{
    return;
}

//Called after transaction is sent/received.
void my_post_trans_cb(spi_slave_transaction_t *trans)
{
    //TO DO - change our yolo state according to what we received from RFID data

	return;
}


void rfidInit()
{
	printf("*** RFID setting init function ***\n");
	unsigned char rc;

    //Configuration for the SPI bus
    spi_bus_config_t buscfg={
        .mosi_io_num=GPIO_MOSI,
        .miso_io_num=GPIO_MISO,
        .sclk_io_num=GPIO_SCLK
    };

    //Configuration for the SPI slave interface
    spi_slave_interface_config_t slvcfg={
        .mode=0,
        .spics_io_num=GPIO_CS,
        .queue_size=3,
        .flags=0,
        .post_setup_cb=my_post_setup_cb,
        .post_trans_cb=my_post_trans_cb
    };

	//Enable pull-ups on SPI lines so we don't detect rogue pulses when no master is connected.
    gpio_set_pull_mode(GPIO_MOSI, GPIO_PULLUP_ONLY);
    gpio_set_pull_mode(GPIO_SCLK, GPIO_PULLUP_ONLY);
    gpio_set_pull_mode(GPIO_CS, GPIO_PULLUP_ONLY);

    //Initialize SPI slave interface
    rc=spi_slave_initialize(HSPI_HOST, &buscfg, &slvcfg, 1);
    printf("spi init status is %d", rc);
    // TO DO - maybe we should add an assert that only rc is OK continue

    memset(recvbuf, 0, sizeof(recvbuf));

    //Set up a transaction of 128 bytes to send/receive
    t.length    = 128*8;
    t.tx_buffer = sendbuf;
    t.rx_buffer = recvbuf;

    //ret=spi_slave_transmit(HSPI_HOST, &t, portMAX_DELAY);

}

void rfidGetYoloSettings()
{

   unsigned char rc;
   unsigned short n;

   n = 0;
   rc = spi_slave_transmit(HSPI_HOST, &t, portMAX_DELAY);

   printf("Received: %s\n", recvbuf);
   n++;

}
