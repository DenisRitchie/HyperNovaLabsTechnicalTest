namespace HyperNovaLabs.Api.Models
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;
    using System.Threading.Tasks;

    [Table(nameof(Bill))]
    public class Bill
    {
        [Key]
        public long Id { get; set; }

        [Required]
        [StringLength(32)]
        public string EmployeeIdentification { get; set; }

        [Required]
        [StringLength(128)]
        public string Concept { get; set; }

        [Column(TypeName = "datetime2")]
        public DateTime DateFrom { get; set; }

        [Column(TypeName = "datetime2")]
        public DateTime DateTo { get; set; }

        [Required]
        [StringLength(32)]
        public string ApprovedBy { get; set; }

        [ForeignKey(nameof(EmployeeIdentification))]
        public Employee Employee { get; set; }

        public ICollection<BillDescription> BillDescriptions { get; set; }
    }
}
