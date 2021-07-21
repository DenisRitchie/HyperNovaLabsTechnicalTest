namespace HyperNovaLabs.Api.Models
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;
    using System.Threading.Tasks;

    [Table(nameof(BillDescription))]
    public class BillDescription
    {
        [Key]
        public long Id { get; set; }

        public long BillId { get; set; }

        [Column(TypeName = "datetime2")]
        public DateTime Date { get; set; }

        [Range(0, Int32.MaxValue)]
        public int Quantity { get; set; }

        [Range(0, UInt32.MaxValue)]
        public double Price { get; set; }

        [Required]
        [StringLength(256)]
        public string Description { get; set; }

        [ForeignKey(nameof(BillId))]
        public Bill Bill { get; set; }
    }
}
